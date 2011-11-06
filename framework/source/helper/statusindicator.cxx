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
#include "precompiled_framework.hxx"

//_______________________________________________
// include files of own module
#include <helper/statusindicator.hxx>
#include <threadhelp/readguard.hxx>
#include <threadhelp/writeguard.hxx>

//_______________________________________________
// namespace

namespace framework{

//_______________________________________________
// declarations

//***********************************************
// XInterface
DEFINE_XINTERFACE_2(StatusIndicator                              ,
                    OWeakObject                                  ,
                    DIRECT_INTERFACE(css::lang::XTypeProvider   ),
                    DIRECT_INTERFACE(css::task::XStatusIndicator))

//***********************************************
// XInterface
DEFINE_XTYPEPROVIDER_2(StatusIndicator            ,
                       css::lang::XTypeProvider   ,
                       css::task::XStatusIndicator)

//***********************************************
StatusIndicator::StatusIndicator(StatusIndicatorFactory* pFactory)
    : ThreadHelpBase     (        )
    , ::cppu::OWeakObject(        )
    , m_xFactory         (pFactory)
{
}

//***********************************************
StatusIndicator::~StatusIndicator()
{
}

//***********************************************
void SAL_CALL StatusIndicator::start(const ::rtl::OUString& sText ,
                                           sal_Int32        nRange)
    throw(css::uno::RuntimeException)
{
    // SAFE ->
    ReadGuard aReadLock(m_aLock);
    css::uno::Reference< css::task::XStatusIndicatorFactory > xFactory(m_xFactory.get(), css::uno::UNO_QUERY);
    aReadLock.unlock();
    // <- SAFE
    if (xFactory.is())
    {
        StatusIndicatorFactory* pFactory = (StatusIndicatorFactory*)xFactory.get();
        pFactory->start(this, sText, nRange);
    }
}

//***********************************************
void SAL_CALL StatusIndicator::end()
    throw(css::uno::RuntimeException)
{
    // SAFE ->
    ReadGuard aReadLock(m_aLock);
    css::uno::Reference< css::task::XStatusIndicatorFactory > xFactory(m_xFactory.get(), css::uno::UNO_QUERY);
    aReadLock.unlock();
    // <- SAFE
    if (xFactory.is())
    {
        StatusIndicatorFactory* pFactory = (StatusIndicatorFactory*)xFactory.get();
        pFactory->end(this);
    }
}

//***********************************************
void SAL_CALL StatusIndicator::reset()
    throw(css::uno::RuntimeException)
{
    // SAFE ->
    ReadGuard aReadLock(m_aLock);
    css::uno::Reference< css::task::XStatusIndicatorFactory > xFactory(m_xFactory.get(), css::uno::UNO_QUERY);
    aReadLock.unlock();
    // <- SAFE
    if (xFactory.is())
    {
        StatusIndicatorFactory* pFactory = (StatusIndicatorFactory*)xFactory.get();
        pFactory->reset(this);
    }
}

//***********************************************
void SAL_CALL StatusIndicator::setText(const ::rtl::OUString& sText)
    throw(css::uno::RuntimeException)
{
    // SAFE ->
    ReadGuard aReadLock(m_aLock);
    css::uno::Reference< css::task::XStatusIndicatorFactory > xFactory(m_xFactory.get(), css::uno::UNO_QUERY);
    aReadLock.unlock();
    // <- SAFE
    if (xFactory.is())
    {
        StatusIndicatorFactory* pFactory = (StatusIndicatorFactory*)xFactory.get();
        pFactory->setText(this, sText);
    }
}

//***********************************************
void SAL_CALL StatusIndicator::setValue(sal_Int32 nValue)
    throw(css::uno::RuntimeException)
{
    // SAFE ->
    ReadGuard aReadLock(m_aLock);
    css::uno::Reference< css::task::XStatusIndicatorFactory > xFactory(m_xFactory.get(), css::uno::UNO_QUERY);
    aReadLock.unlock();
    // <- SAFE
    if (xFactory.is())
    {
        StatusIndicatorFactory* pFactory = (StatusIndicatorFactory*)xFactory.get();
        pFactory->setValue(this, nValue);
    }
}

} // namespace framework
