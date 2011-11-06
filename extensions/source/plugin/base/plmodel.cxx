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
#include <plugin/model.hxx>
#include <com/sun/star/beans/PropertyAttribute.hpp>

using namespace com::sun::star::uno;

//==================================================================================================
Reference< XInterface > SAL_CALL PluginModel_CreateInstance( const Reference< ::com::sun::star::lang::XMultiServiceFactory >  & ) throw( Exception )
{
	Reference< XInterface >  xService = *new PluginModel();
	return xService;
}

Any PluginModel::queryAggregation( const Type& type ) throw( RuntimeException )
{
	Any aRet( ::cppu::queryInterface( type,
									  static_cast< ::com::sun::star::lang::XComponent* >(this),
									  static_cast< ::com::sun::star::io::XPersistObject* >(this ),
									  static_cast< ::com::sun::star::awt::XControlModel* >(this),
									  static_cast< ::com::sun::star::beans::XPropertySet* >(this),
									  static_cast< ::com::sun::star::beans::XMultiPropertySet* >(this),
									  static_cast< ::com::sun::star::beans::XFastPropertySet* >(this)
		) );
	return aRet.hasValue() ? aRet : OWeakAggObject::queryAggregation( type );
}


// XPluginManager_Impl
Sequence< ::rtl::OUString > PluginModel::getSupportedServiceNames_Static(void) throw()
{
	Sequence< ::rtl::OUString > aSNS( 1 );
	aSNS.getArray()[0] = ::rtl::OUString::createFromAscii( "com.sun.star.plugin.PluginModel" );
	return aSNS;
}


static const char* aCreationURL = "URL";
static const char* aMime = "TYPE";

static ::osl::Mutex aPropertyMutex;

static ::com::sun::star::beans::Property aProps[] =
{
	::com::sun::star::beans::Property(
		::rtl::OUString::createFromAscii( aMime ),
		1,
		::getCppuType((const ::rtl::OUString*)0),
		::com::sun::star::beans::PropertyAttribute::BOUND ),
	::com::sun::star::beans::Property(
		::rtl::OUString::createFromAscii( aCreationURL ),
		2,
		::getCppuType((const ::rtl::OUString*)0),
		::com::sun::star::beans::PropertyAttribute::BOUND )
};

PluginModel::PluginModel() :
		BroadcasterHelperHolder( aPropertyMutex ),
		OPropertySetHelper( m_aHelper ),
		OPropertyArrayHelper( aProps, 2 )
{
}

PluginModel::PluginModel(const ::rtl::OUString& rURL, const rtl::OUString& rMimeType ) :
		BroadcasterHelperHolder( aPropertyMutex ),
		OPropertySetHelper( m_aHelper ),
		OPropertyArrayHelper( aProps, 2 ),
		m_aCreationURL( rURL ),
        m_aMimeType( rMimeType )
{
}

PluginModel::~PluginModel()
{
}

Reference< ::com::sun::star::beans::XPropertySetInfo >  PluginModel::getPropertySetInfo() throw()
{
	static Reference< ::com::sun::star::beans::XPropertySetInfo > aInfo =
		createPropertySetInfo( *this );
	return aInfo;
}

::cppu::IPropertyArrayHelper& PluginModel::getInfoHelper()
{
	return *this;
}

sal_Bool PluginModel::convertFastPropertyValue( Any & rConvertedValue,
                                                Any & rOldValue, 
                                                sal_Int32 nHandle,
                                                const Any& rValue ) throw()
{
    if( nHandle == 1 || nHandle == 2 )
    {
        if( rValue.getValueTypeClass() == TypeClass_STRING )   
        {
            rConvertedValue = rValue;
            if( nHandle == 2 )
                rOldValue <<= m_aCreationURL;
            else if( nHandle == 1 )
                rOldValue <<= m_aMimeType;
            return sal_True;
        }
    }
	return sal_False;
}

void PluginModel::setFastPropertyValue_NoBroadcast( sal_Int32 nHandle,
													const Any& rValue )
    throw(::com::sun::star::uno::Exception)
{
	if( rValue.getValueTypeClass() == TypeClass_STRING ) // FIXME wrong type!

	{
        if( nHandle == 2 )
            rValue >>= m_aCreationURL;
        else if( nHandle == 1 )
            rValue >>= m_aMimeType;
	}
	else
		throw ::com::sun::star::lang::IllegalArgumentException();
}

void PluginModel::getFastPropertyValue( Any& rValue, sal_Int32 nHandle ) const throw()
{
    if( nHandle == 2 )
        rValue <<= m_aCreationURL;
    else if( nHandle == 1 )
        rValue <<= m_aMimeType;
}

//---- ::com::sun::star::lang::XComponent ----------------------------------------------------------------------------------
void PluginModel::addEventListener( const Reference< ::com::sun::star::lang::XEventListener > & l ) throw()
{
	m_aDisposeListeners.push_back( l );
}

//---- ::com::sun::star::lang::XComponent ----------------------------------------------------------------------------------
void PluginModel::removeEventListener( const Reference< ::com::sun::star::lang::XEventListener > & l ) throw()
{
	m_aDisposeListeners.remove( l );
}

//---- ::com::sun::star::lang::XComponent ----------------------------------------------------------------------------------
void PluginModel::dispose(void) throw()
{
	// send disposing events
	::com::sun::star::lang::EventObject aEvt;
	aEvt.Source = (::cppu::OWeakObject*)this;
	::std::list< Reference< ::com::sun::star::lang::XEventListener > > aLocalListeners = m_aDisposeListeners;
	for( ::std::list< Reference< ::com::sun::star::lang::XEventListener > >::iterator it = aLocalListeners.begin();
		 it != aLocalListeners.end(); ++it )
		(*it)->disposing( aEvt );

	m_aDisposeListeners.clear();
	
	disposing();
}


// ::com::sun::star::io::XPersistObject
::rtl::OUString PluginModel::getServiceName() throw()
{
	return ::rtl::OUString::createFromAscii( "com.sun.star.plugin.PluginModel" );
}

void PluginModel::write(const Reference< ::com::sun::star::io::XObjectOutputStream > & OutStream) throw()
{
	OutStream->writeUTF( m_aCreationURL );
}

void PluginModel::read(const Reference< ::com::sun::star::io::XObjectInputStream > & InStream) throw()
{
	m_aCreationURL = InStream->readUTF();
}
