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



// MARKER(update_precomp.py): Generated on 2006-09-01 17:49:41.030262

#ifdef PRECOMPILED_HEADERS

//---MARKER---
#include "sal/config.h"
#include "sal/types.h"


#include "boost/scoped_array.hpp"
#include "boost/shared_ptr.hpp"

#include "com/sun/star/awt/FocusChangeReason.hpp"
#include "com/sun/star/awt/FocusEvent.hpp"
#include "com/sun/star/awt/FontDescriptor.hpp"
#include "com/sun/star/awt/FontSlant.hpp"
#include "com/sun/star/awt/FontStrikeout.hpp"
#include "com/sun/star/awt/FontUnderline.hpp"
#include "com/sun/star/awt/FontWeight.hpp"
#include "com/sun/star/awt/Gradient.hpp"
#include "com/sun/star/awt/GradientStyle.hpp"
#include "com/sun/star/awt/InputEvent.hpp"
#include "com/sun/star/awt/Key.hpp"
#include "com/sun/star/awt/KeyEvent.hpp"
#include "com/sun/star/awt/KeyFunction.hpp"
#include "com/sun/star/awt/KeyGroup.hpp"
#include "com/sun/star/awt/KeyModifier.hpp"
#include "com/sun/star/awt/MouseButton.hpp"
#include "com/sun/star/awt/MouseEvent.hpp"
#include "com/sun/star/awt/PaintEvent.hpp"
#include "com/sun/star/awt/PosSize.hpp"
#include "com/sun/star/awt/RasterOperation.hpp"
#include "com/sun/star/awt/Rectangle.hpp"
#include "com/sun/star/awt/Size.hpp"
#include "com/sun/star/awt/VclWindowPeerAttribute.hpp"
#include "com/sun/star/awt/VisualEffect.hpp"
#include "com/sun/star/awt/WindowDescriptor.hpp"
#include "com/sun/star/awt/WindowEvent.hpp"
#include "com/sun/star/awt/XActionListener.hpp"
#include "com/sun/star/awt/XActivateListener.hpp"
#include "com/sun/star/awt/XAdjustmentListener.hpp"
#include "com/sun/star/awt/XBitmap.hpp"
#include "com/sun/star/awt/XControl.hpp"
#include "com/sun/star/awt/XControlContainer.hpp"
#include "com/sun/star/awt/XControlModel.hpp"
#include "com/sun/star/awt/XFocusListener.hpp"
#include "com/sun/star/awt/XGraphics.hpp"
#include "com/sun/star/awt/XItemListener.hpp"
#include "com/sun/star/awt/XKeyListener.hpp"
#include "com/sun/star/awt/XLayoutConstrains.hpp"
#include "com/sun/star/awt/XMouseListener.hpp"
#include "com/sun/star/awt/XMouseMotionListener.hpp"
#include "com/sun/star/awt/XPaintListener.hpp"
#include "com/sun/star/awt/XSpinListener.hpp"
#include "com/sun/star/awt/XSystemChildFactory.hpp"
#include "com/sun/star/awt/XTabController.hpp"
#include "com/sun/star/awt/XTabControllerModel.hpp"
#include "com/sun/star/awt/XTextListener.hpp"
#include "com/sun/star/awt/XTopWindow.hpp"
#include "com/sun/star/awt/XTopWindowListener.hpp"
#include "com/sun/star/awt/XUnoControlContainer.hpp"
#include "com/sun/star/awt/XVclContainer.hpp"
#include "com/sun/star/awt/XVclContainerListener.hpp"
#include "com/sun/star/awt/XVclContainerPeer.hpp"
#include "com/sun/star/awt/XVclWindowPeer.hpp"
#include "com/sun/star/awt/XWindow.hpp"
#include "com/sun/star/awt/XWindowListener.hpp"
#include "com/sun/star/awt/XWindowPeer.hpp"
#include "com/sun/star/beans/MethodConcept.hpp"
#include "com/sun/star/beans/NamedValue.hpp"
#include "com/sun/star/beans/Optional.hpp"
#include "com/sun/star/beans/Property.hpp"
#include "com/sun/star/beans/PropertyAttribute.hpp"
#include "com/sun/star/beans/PropertyChangeEvent.hpp"
#include "com/sun/star/beans/PropertyConcept.hpp"
#include "com/sun/star/beans/PropertyState.hpp"
#include "com/sun/star/beans/PropertyStateChangeEvent.hpp"
#include "com/sun/star/beans/PropertyValue.hpp"
#include "com/sun/star/beans/PropertyValues.hpp"
#include "com/sun/star/beans/UnknownPropertyException.hpp"
#include "com/sun/star/beans/XExactName.hpp"
#include "com/sun/star/beans/XFastPropertySet.hpp"
#include "com/sun/star/beans/XIntrospection.hpp"
#include "com/sun/star/beans/XIntrospectionAccess.hpp"
#include "com/sun/star/beans/XMaterialHolder.hpp"
#include "com/sun/star/beans/XMultiPropertySet.hpp"
#include "com/sun/star/beans/XPropertiesChangeListener.hpp"
#include "com/sun/star/beans/XPropertyAccess.hpp"
#include "com/sun/star/beans/XPropertyChangeListener.hpp"
#include "com/sun/star/beans/XPropertyContainer.hpp"
#include "com/sun/star/beans/XPropertySet.hpp"
#include "com/sun/star/beans/XPropertySetInfo.hpp"
#include "com/sun/star/beans/XPropertyState.hpp"
#include "com/sun/star/beans/XPropertyStateChangeListener.hpp"
#include "com/sun/star/beans/XVetoableChangeListener.hpp"
#include "com/sun/star/bridge/ModelDependent.hpp"
#include "com/sun/star/bridge/XBridgeSupplier2.hpp"
#include "com/sun/star/bridge/XUnoUrlResolver.hpp"
#include "com/sun/star/bridge/oleautomation/Currency.hpp"
#include "com/sun/star/bridge/oleautomation/Date.hpp"
#include "com/sun/star/bridge/oleautomation/Decimal.hpp"
#include "com/sun/star/bridge/oleautomation/NamedArgument.hpp"
#include "com/sun/star/bridge/oleautomation/PropertyPutArgument.hpp"
#include "com/sun/star/bridge/oleautomation/SCode.hpp"
#include "com/sun/star/bridge/oleautomation/XAutomationObject.hpp"
#include "com/sun/star/configuration/backend/BackendAccessException.hpp"
#include "com/sun/star/configuration/backend/CannotConnectException.hpp"
#include "com/sun/star/configuration/backend/ConnectionLostException.hpp"
#include "com/sun/star/configuration/backend/InsufficientAccessRightsException.hpp"
#include "com/sun/star/configuration/backend/PropertyInfo.hpp"
#include "com/sun/star/configuration/backend/XLayer.hpp"
#include "com/sun/star/configuration/backend/XLayerContentDescriber.hpp"
#include "com/sun/star/configuration/backend/XSingleLayerStratum.hpp"
#include "com/sun/star/connection/ConnectionSetupException.hpp"
#include "com/sun/star/container/NoSuchElementException.hpp"
#include "com/sun/star/container/XChild.hpp"
#include "com/sun/star/container/XElementAccess.hpp"
#include "com/sun/star/container/XEnumeration.hpp"
#include "com/sun/star/container/XEnumerationAccess.hpp"
#include "com/sun/star/container/XHierarchicalNameAccess.hpp"
#include "com/sun/star/container/XIndexAccess.hpp"
#include "com/sun/star/container/XNameAccess.hpp"
#include "com/sun/star/container/XNameContainer.hpp"
#include "com/sun/star/container/XNameReplace.hpp"
#include "com/sun/star/container/XNamed.hpp"
#include "com/sun/star/container/XSet.hpp"
#include "com/sun/star/datatransfer/clipboard/XClipboard.hpp"
#include "com/sun/star/document/EventObject.hpp"
#include "com/sun/star/document/XEventBroadcaster.hpp"
#include "com/sun/star/document/XEventListener.hpp"
#include "com/sun/star/form/FormButtonType.hpp"
#include "com/sun/star/form/FormComponentType.hpp"
#include "com/sun/star/form/FormSubmitEncoding.hpp"
#include "com/sun/star/form/ListSourceType.hpp"
#include "com/sun/star/form/XBoundComponent.hpp"
#include "com/sun/star/form/XConfirmDeleteListener.hpp"
#include "com/sun/star/form/XForm.hpp"
#include "com/sun/star/form/XFormController.hpp"
#include "com/sun/star/form/XFormsSupplier.hpp"
#include "com/sun/star/form/XGridColumnFactory.hpp"
#include "com/sun/star/form/XLoadListener.hpp"
#include "com/sun/star/form/XLoadable.hpp"
#include "com/sun/star/form/binding/XBindableValue.hpp"
#include "com/sun/star/form/binding/XListEntrySink.hpp"
#include "com/sun/star/form/binding/XListEntrySource.hpp"
#include "com/sun/star/form/binding/XValueBinding.hpp"
#include "com/sun/star/form/submission/XSubmissionSupplier.hpp"
#include "com/sun/star/frame/CommandGroup.hpp"
#include "com/sun/star/frame/DispatchResultEvent.hpp"
#include "com/sun/star/frame/DispatchResultState.hpp"
#include "com/sun/star/frame/FrameAction.hpp"
#include "com/sun/star/frame/FrameActionEvent.hpp"
#include "com/sun/star/frame/FrameSearchFlag.hpp"
#include "com/sun/star/frame/XComponentLoader.hpp"
#include "com/sun/star/frame/XController.hpp"
#include "com/sun/star/frame/XDesktop.hpp"
#include "com/sun/star/frame/XDispatch.hpp"
#include "com/sun/star/frame/XDispatchHelper.hpp"
#include "com/sun/star/frame/XDispatchInformationProvider.hpp"
#include "com/sun/star/frame/XDispatchProvider.hpp"
#include "com/sun/star/frame/XDispatchProviderInterception.hpp"
#include "com/sun/star/frame/XDispatchProviderInterceptor.hpp"
#include "com/sun/star/frame/XFrame.hpp"
#include "com/sun/star/frame/XFrameActionListener.hpp"
#include "com/sun/star/frame/XFrameLoader.hpp"
#include "com/sun/star/frame/XFrames.hpp"
#include "com/sun/star/frame/XFramesSupplier.hpp"
#include "com/sun/star/frame/XModel.hpp"
#include "com/sun/star/frame/XStatusListener.hpp"
#include "com/sun/star/frame/XStorable.hpp"
#include "com/sun/star/graphic/XGraphicProvider.hpp"
#include "com/sun/star/inspection/LineDescriptor.hpp"
#include "com/sun/star/inspection/PropertyControlType.hpp"
#include "com/sun/star/inspection/PropertyLineElement.hpp"
#include "com/sun/star/inspection/XHyperlinkControl.hpp"
#include "com/sun/star/inspection/XNumericControl.hpp"
#include "com/sun/star/inspection/XObjectInspector.hpp"
#include "com/sun/star/inspection/XObjectInspectorModel.hpp"
#include "com/sun/star/inspection/XObjectInspectorUI.hpp"
#include "com/sun/star/inspection/XPropertyControl.hpp"
#include "com/sun/star/inspection/XPropertyControlFactory.hpp"
#include "com/sun/star/inspection/XPropertyHandler.hpp"
#include "com/sun/star/inspection/XStringListControl.hpp"
#include "com/sun/star/installation/ProtDlgRes.hpp"
#include "com/sun/star/installation/XProtocolHandlerCheck.hpp"
#include "com/sun/star/installation/protocols.hpp"
#include "com/sun/star/io/BufferSizeExceededException.hpp"
#include "com/sun/star/io/IOException.hpp"
#include "com/sun/star/io/NotConnectedException.hpp"
#include "com/sun/star/io/XActiveDataControl.hpp"
#include "com/sun/star/io/XActiveDataSink.hpp"
#include "com/sun/star/io/XActiveDataSource.hpp"
#include "com/sun/star/io/XConnectable.hpp"
#include "com/sun/star/io/XDataInputStream.hpp"
#include "com/sun/star/io/XDataOutputStream.hpp"
#include "com/sun/star/io/XInputStream.hpp"
#include "com/sun/star/io/XMarkableStream.hpp"
#include "com/sun/star/io/XObjectInputStream.hpp"
#include "com/sun/star/io/XObjectOutputStream.hpp"
#include "com/sun/star/io/XOutputStream.hpp"
#include "com/sun/star/io/XPersistObject.hpp"
#include "com/sun/star/io/XSeekable.hpp"
#include "com/sun/star/io/XStreamListener.hpp"
#include "com/sun/star/io/XXMLExtractor.hpp"
#include "com/sun/star/lang/DisposedException.hpp"
#include "com/sun/star/lang/EventObject.hpp"
#include "com/sun/star/lang/IllegalArgumentException.hpp"
#include "com/sun/star/lang/IndexOutOfBoundsException.hpp"
#include "com/sun/star/lang/NullPointerException.hpp"
#include "com/sun/star/lang/ServiceNotRegisteredException.hpp"
#include "com/sun/star/lang/SystemDependent.hpp"
#include "com/sun/star/lang/WrappedTargetException.hpp"
#include "com/sun/star/lang/XComponent.hpp"
#include "com/sun/star/lang/XEventListener.hpp"
#include "com/sun/star/lang/XInitialization.hpp"
#include "com/sun/star/lang/XLocalizable.hpp"
#include "com/sun/star/lang/XMultiComponentFactory.hpp"
#include "com/sun/star/lang/XMultiServiceFactory.hpp"
#include "com/sun/star/lang/XServiceInfo.hpp"
#include "com/sun/star/lang/XServiceName.hpp"
#include "com/sun/star/lang/XSingleServiceFactory.hpp"
#include "com/sun/star/lang/XTypeProvider.hpp"
#include "com/sun/star/lang/XUnoTunnel.hpp"
#include "com/sun/star/ldap/LdapConnectionException.hpp"
#include "com/sun/star/ldap/LdapGenericException.hpp"
#include "com/sun/star/loader/CannotActivateFactoryException.hpp"
#include "com/sun/star/loader/XImplementationLoader.hpp"
#include "com/sun/star/plugin/PluginDescription.hpp"
#include "com/sun/star/plugin/PluginException.hpp"
#include "com/sun/star/plugin/PluginMode.hpp"
#include "com/sun/star/plugin/PluginVariable.hpp"
#include "com/sun/star/plugin/XPlugin.hpp"
#include "com/sun/star/plugin/XPluginContext.hpp"
#include "com/sun/star/plugin/XPluginManager.hpp"
#include "com/sun/star/reflection/InvocationTargetException.hpp"
#include "com/sun/star/reflection/ParamInfo.hpp"
#include "com/sun/star/reflection/XEnumTypeDescription.hpp"
#include "com/sun/star/reflection/XIdlReflection.hpp"
#include "com/sun/star/registry/InvalidRegistryException.hpp"
#include "com/sun/star/registry/InvalidValueException.hpp"
#include "com/sun/star/registry/RegistryKeyType.hpp"
#include "com/sun/star/registry/RegistryValueType.hpp"
#include "com/sun/star/registry/XRegistryKey.hpp"
#include "com/sun/star/registry/XSimpleRegistry.hpp"
#include "com/sun/star/resource/XResourceBundleLoader.hpp"
#include "com/sun/star/scanner/ScannerException.hpp"
#include "com/sun/star/scanner/XScannerManager.hpp"
#include "com/sun/star/script/ContextInformation.hpp"
#include "com/sun/star/script/FailReason.hpp"
#include "com/sun/star/script/FinishEngineEvent.hpp"
#include "com/sun/star/script/FinishReason.hpp"
#include "com/sun/star/script/InterruptEngineEvent.hpp"
#include "com/sun/star/script/InterruptReason.hpp"
#include "com/sun/star/script/InvocationInfo.hpp"
#include "com/sun/star/script/MemberType.hpp"
#include "com/sun/star/script/ScriptEventDescriptor.hpp"
#include "com/sun/star/script/XDebugging.hpp"
#include "com/sun/star/script/XEngine.hpp"
#include "com/sun/star/script/XEngineListener.hpp"
#include "com/sun/star/script/XEventAttacherManager.hpp"
#include "com/sun/star/script/XInvocation.hpp"
#include "com/sun/star/script/XInvocation2.hpp"
#include "com/sun/star/script/XInvocationAdapterFactory.hpp"
#include "com/sun/star/script/XInvocationAdapterFactory2.hpp"
#include "com/sun/star/script/XLibraryAccess.hpp"
#include "com/sun/star/script/XScriptEventsSupplier.hpp"
#include "com/sun/star/script/XTypeConverter.hpp"
#include "com/sun/star/sdb/CommandType.hpp"
#include "com/sun/star/sdb/RowChangeAction.hpp"
#include "com/sun/star/sdb/SQLContext.hpp"
#include "com/sun/star/sdb/XColumn.hpp"
#include "com/sun/star/sdb/XCompletedConnection.hpp"
#include "com/sun/star/sdb/XDatabaseEnvironment.hpp"
#include "com/sun/star/sdb/XDocumentDataSource.hpp"
#include "com/sun/star/sdb/XQueriesSupplier.hpp"
#include "com/sun/star/sdb/XSingleSelectQueryComposer.hpp"
#include "com/sun/star/sdbc/DataType.hpp"
#include "com/sun/star/sdbc/ResultSetConcurrency.hpp"
#include "com/sun/star/sdbc/ResultSetType.hpp"
#include "com/sun/star/sdbc/SQLWarning.hpp"
#include "com/sun/star/sdbc/XConnection.hpp"
#include "com/sun/star/sdbc/XDataSource.hpp"
#include "com/sun/star/sdbc/XDatabaseMetaData.hpp"
#include "com/sun/star/sdbc/XDriverAccess.hpp"
#include "com/sun/star/sdbc/XPreparedStatement.hpp"
#include "com/sun/star/sdbc/XResultSet.hpp"
#include "com/sun/star/sdbc/XResultSetUpdate.hpp"
#include "com/sun/star/sdbc/XRowSet.hpp"
#include "com/sun/star/sdbc/XRowSetListener.hpp"
#include "com/sun/star/sdbcx/KeyType.hpp"
#include "com/sun/star/sdbcx/Privilege.hpp"
#include "com/sun/star/sdbcx/XColumnsSupplier.hpp"
#include "com/sun/star/sdbcx/XKeysSupplier.hpp"
#include "com/sun/star/sdbcx/XRowLocate.hpp"
#include "com/sun/star/sdbcx/XTablesSupplier.hpp"
#include "com/sun/star/sheet/XSpreadsheetDocument.hpp"
#include "com/sun/star/sheet/XSpreadsheetView.hpp"
#include "com/sun/star/svg/XSVGPrinter.hpp"
#include "com/sun/star/svg/XSVGWriter.hpp"
#include "com/sun/star/system/SystemShellExecuteException.hpp"
#include "com/sun/star/system/SystemShellExecuteFlags.hpp"
#include "com/sun/star/system/XSystemShellExecute.hpp"
#include "com/sun/star/table/CellAddress.hpp"
#include "com/sun/star/table/CellRangeAddress.hpp"
#include "com/sun/star/table/XCellRange.hpp"
#include "com/sun/star/task/XInteractionAbort.hpp"
#include "com/sun/star/task/XInteractionApprove.hpp"
#include "com/sun/star/task/XInteractionContinuation.hpp"
#include "com/sun/star/task/XInteractionDisapprove.hpp"
#include "com/sun/star/task/XInteractionHandler.hpp"
#include "com/sun/star/task/XInteractionRequest.hpp"
#include "com/sun/star/task/XInteractionRetry.hpp"
#include "com/sun/star/task/XJob.hpp"
#include "com/sun/star/text/BibliographyDataField.hpp"
#include "com/sun/star/text/TextContentAnchorType.hpp"
#include "com/sun/star/ucb/AlreadyInitializedException.hpp"
#include "com/sun/star/ucb/Command.hpp"
#include "com/sun/star/ucb/CommandAbortedException.hpp"
#include "com/sun/star/ucb/ContentEvent.hpp"
#include "com/sun/star/ucb/IOErrorCode.hpp"
#include "com/sun/star/ucb/IllegalIdentifierException.hpp"
#include "com/sun/star/ucb/InteractiveAugmentedIOException.hpp"
#include "com/sun/star/ucb/InteractiveWrongMediumException.hpp"
#include "com/sun/star/ucb/PostCommandArgument.hpp"
#include "com/sun/star/ucb/PostCommandArgument2.hpp"
#include "com/sun/star/ucb/XCommandEnvironment.hpp"
#include "com/sun/star/ucb/XCommandInfo.hpp"
#include "com/sun/star/ucb/XCommandProcessor.hpp"
#include "com/sun/star/ucb/XCommandProcessor2.hpp"
#include "com/sun/star/ucb/XContent.hpp"
#include "com/sun/star/ucb/XContentAccess.hpp"
#include "com/sun/star/ucb/XContentEventListener.hpp"
#include "com/sun/star/ucb/XContentIdentifier.hpp"
#include "com/sun/star/ucb/XContentIdentifierFactory.hpp"
#include "com/sun/star/ucb/XContentProvider.hpp"
#include "com/sun/star/ucb/XProgressHandler.hpp"
#include "com/sun/star/ucb/XSimpleFileAccess.hpp"
#include "com/sun/star/ui/dialogs/ExtendedFilePickerElementIds.hpp"
#include "com/sun/star/ui/dialogs/TemplateDescription.hpp"
#include "com/sun/star/ui/dialogs/XExecutableDialog.hpp"
#include "com/sun/star/ui/dialogs/XFilePickerControlAccess.hpp"
#include "com/sun/star/uno/Any.h"
#include "com/sun/star/uno/Any.hxx"
#include "com/sun/star/uno/Exception.hpp"
#include "com/sun/star/uno/Reference.h"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/RuntimeException.hpp"
#include "com/sun/star/uno/Sequence.h"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.h"
#include "com/sun/star/uno/Type.hxx"
#include "com/sun/star/uno/TypeClass.hpp"
#include "com/sun/star/uno/XAdapter.hpp"
#include "com/sun/star/uno/XComponentContext.hpp"
#include "com/sun/star/uno/XInterface.hpp"
#include "com/sun/star/uno/XNamingService.hpp"
#include "com/sun/star/uno/XReference.hpp"
#include "com/sun/star/uno/genfunc.h"
#include "com/sun/star/util/AliasProgrammaticPair.hpp"
#include "com/sun/star/util/ChangesSet.hpp"
#include "com/sun/star/util/Color.hpp"
#include "com/sun/star/util/Date.hpp"
#include "com/sun/star/util/DateTime.hpp"
#include "com/sun/star/util/ElementChange.hpp"
#include "com/sun/star/util/MeasureUnit.hpp"
#include "com/sun/star/util/NumberFormat.hpp"
#include "com/sun/star/util/Time.hpp"
#include "com/sun/star/util/URL.hpp"
#include "com/sun/star/util/XArchiver.hpp"
#include "com/sun/star/util/XChangesBatch.hpp"
#include "com/sun/star/util/XChangesListener.hpp"
#include "com/sun/star/util/XChangesNotifier.hpp"
#include "com/sun/star/util/XCloseBroadcaster.hpp"
#include "com/sun/star/util/XCloseListener.hpp"
#include "com/sun/star/util/XCloseable.hpp"
#include "com/sun/star/util/XLocalizedAliases.hpp"
#include "com/sun/star/util/XModifiable.hpp"
#include "com/sun/star/util/XNumberFormatTypes.hpp"
#include "com/sun/star/util/XNumberFormatsSupplier.hpp"
#include "com/sun/star/util/XTimeStamped.hpp"
#include "com/sun/star/util/XURLTransformer.hpp"
#include "com/sun/star/view/XSelectionSupplier.hpp"
#include "com/sun/star/xforms/XDataTypeRepository.hpp"
#include "com/sun/star/xforms/XFormsSupplier.hpp"
#include "com/sun/star/xforms/XFormsUIHelper1.hpp"
#include "com/sun/star/xforms/XModel.hpp"
#include "com/sun/star/xforms/XSubmission.hpp"
#include "com/sun/star/xml/sax/XDocumentHandler.hpp"
#include "com/sun/star/xml/sax/XExtendedDocumentHandler.hpp"
#include "com/sun/star/xsd/DataTypeClass.hpp"
#include "com/sun/star/xsd/WhiteSpaceTreatment.hpp"
#include "com/sun/star/xsd/XDataType.hpp"

#include "comphelper/broadcasthelper.hxx"
#include "comphelper/container.hxx"
#include "comphelper/documentconstants.hxx"
#include "comphelper/interaction.hxx"
#include "comphelper/listenernotification.hxx"
#include "comphelper/namedvaluecollection.hxx"
#include "comphelper/processfactory.hxx"
#include "comphelper/sequence.hxx"
#include "comphelper/types.hxx"
#include "comphelper/uno3.hxx"

#include "connectivity/dbconversion.hxx"
#include "connectivity/dbexception.hxx"

#include "cppu/macros.hxx"
#include "cppu/unotype.hxx"

#include "cppuhelper/bootstrap.hxx"
#include "cppuhelper/compbase1.hxx"
#include "cppuhelper/component_context.hxx"
#include "cppuhelper/exc_hlp.hxx"
#include "cppuhelper/factory.hxx"
#include "cppuhelper/implbase1.hxx"
#include "cppuhelper/implbase2.hxx"
#include "cppuhelper/implbase3.hxx"
#include "cppuhelper/implbase4.hxx"
#include "cppuhelper/implbase5.hxx"
#include "cppuhelper/implbase7.hxx"
#include "cppuhelper/implementationentry.hxx"
#include "cppuhelper/interfacecontainer.h"
#include "cppuhelper/interfacecontainer.hxx"
#include "cppuhelper/propshlp.hxx"
#include "cppuhelper/servicefactory.hxx"
#include "cppuhelper/typeprovider.hxx"
#include "cppuhelper/weak.hxx"
#include "cppuhelper/weakagg.hxx"
#include "cppuhelper/weakref.hxx"



#include "i18npool/mslangid.hxx"




#include "osl/conditn.h"
#include "osl/diagnose.h"
#include "osl/doublecheckedlocking.h"
#include "osl/file.hxx"
#include "osl/getglobalmutex.hxx"
#include "osl/interlck.h"
#include "osl/module.h"
#include "osl/module.hxx"
#include "osl/mutex.hxx"
#include "osl/nlsupport.h"
#include "osl/process.h"
#include "osl/security.hxx"
#include "osl/thread.h"
#include "osl/time.h"


#include "rtl/alloc.h"
#include "rtl/bootstrap.hxx"
#include "rtl/byteseq.h"
#include "rtl/instance.hxx"
#include "rtl/locale.h"
#include "rtl/math.hxx"
#include "rtl/memory.h"
#include "rtl/process.h"
#include "rtl/strbuf.hxx"
#include "rtl/string.h"
#include "rtl/string.hxx"
#include "rtl/textenc.h"
#include "rtl/unload.h"
#include "rtl/ustrbuf.hxx"
#include "rtl/ustring.hxx"
#include "rtl/uuid.h"

#include "salhelper/simplereferenceobject.hxx"

#include "sane/sane.h"





#include "svl/filenotation.hxx"
#include "svtools/imgdef.hxx"
#include "svtools/miscopt.hxx"
#include "unotools/moduleoptions.hxx"
#include "svl/numuno.hxx"

#include "svx/flagsdef.hxx"

#include "sys/stat.h"
#include "sys/types.h"


#include "tools/diagnose_ex.h"


#include "typelib/typeclass.h"
#include "typelib/typedescription.h"
#include "typelib/typedescription.hxx"


#include "uno/dispatcher.h"
#include "uno/environment.h"
#include "uno/lbnames.h"

#include "unotools/configitem.hxx"
#include "unotools/confignode.hxx"
#include "unotools/processfactory.hxx"


#include "tools/fldunit.hxx"

#include "vos/conditn.hxx"
#include "vos/diagnose.hxx"
#include "vos/macros.hxx"
#include "vos/module.hxx"
#include "vos/mutex.hxx"
#include "vos/pipe.hxx"
#include "vos/ref.hxx"
#include "vos/refernce.hxx"
#include "vos/thread.hxx"
#include "vos/timer.hxx"

#include "xmloff/nmspmap.hxx"
//---MARKER---

#endif