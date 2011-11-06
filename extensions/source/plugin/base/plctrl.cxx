/**************************************************************
 * 
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 * 
 *   http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 * 
 *************************************************************/



// MARKER(update_precomp.py): autogen include statement, do not remove
#include "precompiled_extensions.hxx"
#include <com/sun/star/awt/XAdjustmentListener.hpp>
#include <com/sun/star/awt/XActionListener.hpp>
#include <com/sun/star/awt/XTextListener.hpp>
#include <com/sun/star/awt/XSpinListener.hpp>
#include <com/sun/star/awt/XItemListener.hpp>
#include <com/sun/star/awt/XVclContainerListener.hpp>

#include <plugin/plctrl.hxx>
#include <vcl/syschild.hxx>
#include <toolkit/helper/vclunohelper.hxx>


//--------------------------------------------------------------------------------------------------
PluginControl_Impl::PluginControl_Impl() :
	_pMultiplexer( NULL )
	, _nX( 0 )
	, _nY( 0 )
	, _nWidth( 100 )
	, _nHeight( 100 )
	, _nFlags( WINDOW_POSSIZE_ALL )
	, _bVisible( sal_False )
	, _bInDesignMode( sal_False )
	, _bEnable( sal_True )
{
}

//--------------------------------------------------------------------------------------------------
PluginControl_Impl::~PluginControl_Impl()
{
}

MRCListenerMultiplexerHelper* PluginControl_Impl::getMultiplexer()
{
	if( ! _pMultiplexer )
		_pMultiplexer = new MRCListenerMultiplexerHelper( this, _xPeerWindow );
	return _pMultiplexer;
}
//==================================================================================================

void PluginControl_Impl::addEventListener( const Reference< ::com::sun::star::lang::XEventListener > & l )
	throw( RuntimeException )
{
	_aDisposeListeners.push_back( l );
}

//---- ::com::sun::star::lang::XComponent ----------------------------------------------------------------------------------
void PluginControl_Impl::removeEventListener( const Reference< ::com::sun::star::lang::XEventListener > & l )
	throw( RuntimeException )
{
	_aDisposeListeners.remove( l );
}

//---- ::com::sun::star::lang::XComponent ----------------------------------------------------------------------------------
void PluginControl_Impl::dispose(void)
	throw( RuntimeException )
{
	// send disposing events
	::com::sun::star::lang::EventObject aEvt;
	if( getMultiplexer() )
		getMultiplexer()->disposeAndClear();

	// release context
	_xContext = Reference< XInterface > ();
	releasePeer();
}


//---- ::com::sun::star::awt::XWindow -------------------------------------------------------------------------------------
void PluginControl_Impl::setPosSize( sal_Int32 nX_, sal_Int32 nY_, sal_Int32 nWidth_, sal_Int32 nHeight_, sal_Int16 nFlags )
	throw( RuntimeException )
{
	_nX			= nX_ >=0 ? nX_ : 0;
	_nY			= nY_ >=0 ? nY_ : 0;
	_nWidth		= nWidth_ >=0 ? nWidth_ : 0;
	_nHeight	= nHeight_ >=0 ? nHeight_ : 0;
	_nFlags		= nFlags;

	if (_xPeerWindow.is())
		_xPeerWindow->setPosSize( _nX, _nY, _nWidth, _nHeight, nFlags );
}

//---- ::com::sun::star::awt::XWindow -------------------------------------------------------------------------------------
::com::sun::star::awt::Rectangle PluginControl_Impl::getPosSize(void)
	throw( RuntimeException )
{
	return _xPeerWindow->getPosSize();
}

//---- ::com::sun::star::awt::XWindow -------------------------------------------------------------------------------------
void PluginControl_Impl::setVisible( sal_Bool bVisible )
	throw( RuntimeException )
{
	_bVisible = bVisible;
	if (_xPeerWindow.is())
		_xPeerWindow->setVisible( _bVisible && !_bInDesignMode );
}
	
//---- ::com::sun::star::awt::XWindow -------------------------------------------------------------------------------------
void PluginControl_Impl::setEnable( sal_Bool bEnable )
	throw( RuntimeException )
{
	_bEnable = bEnable;
	if (_xPeerWindow.is())
		_xPeerWindow->setEnable( _bEnable );
}
	
//---- ::com::sun::star::awt::XWindow -------------------------------------------------------------------------------------
void PluginControl_Impl::setFocus(void) throw( RuntimeException )
{
	if (_xPeerWindow.is())
		_xPeerWindow->setFocus();
}


//--------------------------------------------------------------------------------------------------
void PluginControl_Impl::releasePeer()
{
	if (_xPeer.is())
	{
		_xParentWindow->removeFocusListener( this );
		_xPeerWindow->dispose();
		_pSysChild		= NULL;
		_xPeerWindow	= Reference< ::com::sun::star::awt::XWindow > ();
		_xPeer			= Reference< ::com::sun::star::awt::XWindowPeer > ();
		getMultiplexer()->setPeer( Reference< ::com::sun::star::awt::XWindow > () );
	}
}

//---- ::com::sun::star::awt::XControl ------------------------------------------------------------------------------------
void PluginControl_Impl::createPeer( const Reference< ::com::sun::star::awt::XToolkit > & /*xToolkit*/, const Reference< ::com::sun::star::awt::XWindowPeer >  & xParentPeer )
	throw( RuntimeException )
{
	if (_xPeer.is())
	{
		DBG_ERROR( "### Peer is already set!" );
		return;
    }

	_xParentPeer = xParentPeer;
	_xParentWindow = Reference< ::com::sun::star::awt::XWindow > ( xParentPeer, UNO_QUERY );
	DBG_ASSERT( _xParentWindow.is(), "### no parent peer window!" );
	
	Window* pImpl = VCLUnoHelper::GetWindow( xParentPeer );
	if (pImpl)
	{
        _pSysChild = new SystemChildWindow( pImpl, WB_CLIPCHILDREN );
        if (pImpl->HasFocus())
            _pSysChild->GrabFocus();
        
		// get peer
		_xPeer			= Reference< ::com::sun::star::awt::XWindowPeer > ( _pSysChild->GetComponentInterface() );
		_xPeerWindow	= Reference< ::com::sun::star::awt::XWindow > ( _xPeer, UNO_QUERY );
		// !_BOTH_ MUST BE VALID!
		DBG_ASSERT( (_xPeer.is() && _xPeerWindow.is()), "### no peer!" );
		
		_xParentWindow->addFocusListener( this );
		_xPeerWindow->setPosSize( _nX, _nY, _nWidth, _nHeight, _nFlags );
		_xPeerWindow->setEnable( _bEnable );
		_xPeerWindow->setVisible( _bVisible && !_bInDesignMode );
	}
	else
	{
		DBG_ERROR( "### cannot get implementation of parent peer!" );
	}

	getMultiplexer()->setPeer( _xPeerWindow );
}

//---- ::com::sun::star::awt::XControl ------------------------------------------------------------------------------------
void PluginControl_Impl::setDesignMode( sal_Bool bOn )
	throw( RuntimeException )
{
	_bInDesignMode = bOn;
	if (_xPeerWindow.is())
		_xPeerWindow->setVisible( _bVisible && !_bInDesignMode );
}

//---- ::com::sun::star::awt::XWindow -------------------------------------------------------------------------------------
void PluginControl_Impl::addPaintListener( const Reference< ::com::sun::star::awt::XPaintListener > & l )
	throw( RuntimeException )
{
	getMultiplexer()->advise( ::getCppuType((const Reference< ::com::sun::star::awt::XPaintListener >*)0), l );
}

//---- ::com::sun::star::awt::XWindow -------------------------------------------------------------------------------------
void PluginControl_Impl::removePaintListener( const Reference< ::com::sun::star::awt::XPaintListener > & l )
	throw( RuntimeException )
{
	getMultiplexer()->unadvise( ::getCppuType((const Reference< ::com::sun::star::awt::XPaintListener >*)0), l );
}

//---- ::com::sun::star::awt::XWindow -------------------------------------------------------------------------------------
void PluginControl_Impl::addWindowListener(	const Reference< ::com::sun::star::awt::XWindowListener > & l )
	throw( RuntimeException )
{
	getMultiplexer()->advise( ::getCppuType((const Reference< ::com::sun::star::awt::XWindowListener >*)0), l );
}

//---- ::com::sun::star::awt::XWindow -------------------------------------------------------------------------------------
void PluginControl_Impl::removeWindowListener( const Reference< ::com::sun::star::awt::XWindowListener > & l )
	throw( RuntimeException )
{
	getMultiplexer()->unadvise( ::getCppuType((const Reference< ::com::sun::star::awt::XWindowListener >*)0), l );
}

//---- ::com::sun::star::awt::XWindow -------------------------------------------------------------------------------------
void PluginControl_Impl::addFocusListener( const Reference< ::com::sun::star::awt::XFocusListener > & l )
	throw( RuntimeException )
{
	getMultiplexer()->advise( ::getCppuType((const Reference< ::com::sun::star::awt::XFocusListener >*)0), l );
}

//---- ::com::sun::star::awt::XWindow -------------------------------------------------------------------------------------
void PluginControl_Impl::removeFocusListener( const Reference< ::com::sun::star::awt::XFocusListener > & l )
	throw( RuntimeException )
{
	getMultiplexer()->unadvise( ::getCppuType((const Reference< ::com::sun::star::awt::XFocusListener >*)0), l );
}

//---- ::com::sun::star::awt::XWindow -------------------------------------------------------------------------------------
void PluginControl_Impl::addKeyListener( const Reference< ::com::sun::star::awt::XKeyListener > & l )
	throw( RuntimeException )
{
	getMultiplexer()->advise( ::getCppuType((const Reference< ::com::sun::star::awt::XKeyListener >*)0), l );
}

//---- ::com::sun::star::awt::XWindow -------------------------------------------------------------------------------------
void PluginControl_Impl::removeKeyListener( const Reference< ::com::sun::star::awt::XKeyListener > & l )
	throw( RuntimeException )
{
	getMultiplexer()->unadvise( ::getCppuType((const Reference< ::com::sun::star::awt::XKeyListener >*)0), l );
}

//---- ::com::sun::star::awt::XWindow -------------------------------------------------------------------------------------
void PluginControl_Impl::addMouseListener( const Reference< ::com::sun::star::awt::XMouseListener > & l )
	throw( RuntimeException )
{
	getMultiplexer()->advise( ::getCppuType((const Reference< ::com::sun::star::awt::XMouseListener >*)0), l );
}

//---- ::com::sun::star::awt::XWindow -------------------------------------------------------------------------------------
void PluginControl_Impl::removeMouseListener( const Reference< ::com::sun::star::awt::XMouseListener > & l )
	throw( RuntimeException )
{
	getMultiplexer()->unadvise( ::getCppuType((const Reference< ::com::sun::star::awt::XMouseListener >*)0), l );
}

//---- ::com::sun::star::awt::XWindow -------------------------------------------------------------------------------------
void PluginControl_Impl::addMouseMotionListener( const Reference< ::com::sun::star::awt::XMouseMotionListener > & l )
	throw( RuntimeException )
{
	getMultiplexer()->advise( ::getCppuType((const Reference< ::com::sun::star::awt::XMouseMotionListener >*)0), l );
}

//---- ::com::sun::star::awt::XWindow -------------------------------------------------------------------------------------
void PluginControl_Impl::removeMouseMotionListener( const Reference< ::com::sun::star::awt::XMouseMotionListener > & l )
	throw( RuntimeException )
{
	getMultiplexer()->unadvise( ::getCppuType((const Reference< ::com::sun::star::awt::XMouseMotionListener >*)0), l );
}


//---- ::com::sun::star::awt::XView ---------------------------------------------------------------------------------------
void PluginControl_Impl::draw( sal_Int32 /*x*/, sal_Int32 /*y*/ )
	throw( RuntimeException )
{
	// has to be done by further implementation of control
}

//---- ::com::sun::star::awt::XView ---------------------------------------------------------------------------------------
void PluginControl_Impl::setZoom( float /*ZoomX*/, float /*ZoomY*/ )
	throw( RuntimeException )
{
	// has to be done by further implementation of control
}

//---- ::com::sun::star::lang::XEventListener ------------------------------------------------------------------------------
void PluginControl_Impl::disposing( const ::com::sun::star::lang::EventObject & /*rSource*/ )
	throw( RuntimeException )
{
}
//---- ::com::sun::star::awt::XFocusListener ------------------------------------------------------------------------------
void PluginControl_Impl::focusGained( const ::com::sun::star::awt::FocusEvent & /*rEvt*/ )
	throw( RuntimeException )
{
	if (_xPeerWindow.is())
		_xPeerWindow->setFocus();
}
//---- ::com::sun::star::awt::XFocusListener ------------------------------------------------------------------------------
void PluginControl_Impl::focusLost( const ::com::sun::star::awt::FocusEvent & /*rEvt*/ )
	throw( RuntimeException )
{
}

