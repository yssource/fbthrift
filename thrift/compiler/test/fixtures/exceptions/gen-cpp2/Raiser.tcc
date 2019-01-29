/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#pragma once

#include "src/gen-cpp2/Raiser.h"

#include <folly/io/IOBuf.h>
#include <folly/io/IOBufQueue.h>
#include <thrift/lib/cpp/TApplicationException.h>
#include <thrift/lib/cpp/transport/THeader.h>
#include <thrift/lib/cpp2/GeneratedCodeHelper.h>
#include <thrift/lib/cpp2/GeneratedSerializationCodeHelper.h>
#include <thrift/lib/cpp2/gen/service_tcc.h>
#include <thrift/lib/cpp2/server/Cpp2ConnContext.h>

namespace cpp2 {
typedef apache::thrift::ThriftPresult<false> Raiser_doBland_pargs;
typedef apache::thrift::ThriftPresult<true> Raiser_doBland_presult;
typedef apache::thrift::ThriftPresult<false> Raiser_doRaise_pargs;
typedef apache::thrift::ThriftPresult<true, apache::thrift::FieldData<1, apache::thrift::protocol::T_STRUCT,  ::cpp2::Banal>, apache::thrift::FieldData<2, apache::thrift::protocol::T_STRUCT,  ::cpp2::Fiery>, apache::thrift::FieldData<3, apache::thrift::protocol::T_STRUCT,  ::cpp2::Serious>> Raiser_doRaise_presult;
typedef apache::thrift::ThriftPresult<false> Raiser_get200_pargs;
typedef apache::thrift::ThriftPresult<true, apache::thrift::FieldData<0, apache::thrift::protocol::T_STRING, std::string*>> Raiser_get200_presult;
typedef apache::thrift::ThriftPresult<false> Raiser_get500_pargs;
typedef apache::thrift::ThriftPresult<true, apache::thrift::FieldData<0, apache::thrift::protocol::T_STRING, std::string*>, apache::thrift::FieldData<1, apache::thrift::protocol::T_STRUCT,  ::cpp2::Fiery>, apache::thrift::FieldData<2, apache::thrift::protocol::T_STRUCT,  ::cpp2::Banal>, apache::thrift::FieldData<3, apache::thrift::protocol::T_STRUCT,  ::cpp2::Serious>> Raiser_get500_presult;
template <typename ProtocolIn_, typename ProtocolOut_>
void RaiserAsyncProcessor::_processInThread_doBland(std::unique_ptr<apache::thrift::ResponseChannelRequest> req, std::unique_ptr<folly::IOBuf> buf, std::unique_ptr<ProtocolIn_> iprot, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) {
  auto pri = iface_->getRequestPriority(ctx, apache::thrift::concurrency::NORMAL);
  processInThread<ProtocolIn_, ProtocolOut_>(std::move(req), std::move(buf),std::move(iprot), ctx, eb, tm, pri, apache::thrift::RpcKind::SINGLE_REQUEST_SINGLE_RESPONSE, &RaiserAsyncProcessor::process_doBland<ProtocolIn_, ProtocolOut_>, this);
}
template <typename ProtocolIn_, typename ProtocolOut_>
void RaiserAsyncProcessor::process_doBland(std::unique_ptr<apache::thrift::ResponseChannelRequest> req, std::unique_ptr<folly::IOBuf> buf, std::unique_ptr<ProtocolIn_> iprot,apache::thrift::Cpp2RequestContext* ctx,folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) {
  // make sure getConnectionContext is null
  // so async calls don't accidentally use it
  iface_->setConnectionContext(nullptr);
  Raiser_doBland_pargs args;
  std::unique_ptr<apache::thrift::ContextStack> ctxStack(this->getContextStack(this->getServiceName(), "Raiser.doBland", ctx));
  try {
    deserializeRequest(args, buf.get(), iprot.get(), ctxStack.get());
  }
  catch (const std::exception& ex) {
    apache::thrift::detail::ap::process_handle_exn_deserialization<ProtocolOut_>(
        ex, std::move(req), ctx, eb, "doBland");
    return;
  }
  req->setStartedProcessing();
  auto callback = std::make_unique<apache::thrift::HandlerCallback<void>>(std::move(req), std::move(ctxStack), return_doBland<ProtocolIn_,ProtocolOut_>, throw_wrapped_doBland<ProtocolIn_, ProtocolOut_>, ctx->getProtoSeqId(), eb, tm, ctx);
  if (!callback->isRequestActive()) {
    callback.release()->deleteInThread();
    return;
  }
  ctx->setStartedProcessing();
  iface_->async_tm_doBland(std::move(callback));
}

template <class ProtocolIn_, class ProtocolOut_>
folly::IOBufQueue RaiserAsyncProcessor::return_doBland(int32_t protoSeqId, apache::thrift::ContextStack* ctx) {
  ProtocolOut_ prot;
  Raiser_doBland_presult result;
  return serializeResponse("doBland", &prot, protoSeqId, ctx, result);
}

template <class ProtocolIn_, class ProtocolOut_>
void RaiserAsyncProcessor::throw_wrapped_doBland(std::unique_ptr<apache::thrift::ResponseChannelRequest> req,int32_t protoSeqId,apache::thrift::ContextStack* ctx,folly::exception_wrapper ew,apache::thrift::Cpp2RequestContext* reqCtx) {
  if (!ew) {
    return;
  }
  {
    (void)protoSeqId;
    apache::thrift::detail::ap::process_throw_wrapped_handler_error<ProtocolOut_>(
        ew, std::move(req), reqCtx, ctx, "doBland");
    return;
  }
}

template <typename ProtocolIn_, typename ProtocolOut_>
void RaiserAsyncProcessor::_processInThread_doRaise(std::unique_ptr<apache::thrift::ResponseChannelRequest> req, std::unique_ptr<folly::IOBuf> buf, std::unique_ptr<ProtocolIn_> iprot, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) {
  auto pri = iface_->getRequestPriority(ctx, apache::thrift::concurrency::NORMAL);
  processInThread<ProtocolIn_, ProtocolOut_>(std::move(req), std::move(buf),std::move(iprot), ctx, eb, tm, pri, apache::thrift::RpcKind::SINGLE_REQUEST_SINGLE_RESPONSE, &RaiserAsyncProcessor::process_doRaise<ProtocolIn_, ProtocolOut_>, this);
}
template <typename ProtocolIn_, typename ProtocolOut_>
void RaiserAsyncProcessor::process_doRaise(std::unique_ptr<apache::thrift::ResponseChannelRequest> req, std::unique_ptr<folly::IOBuf> buf, std::unique_ptr<ProtocolIn_> iprot,apache::thrift::Cpp2RequestContext* ctx,folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) {
  // make sure getConnectionContext is null
  // so async calls don't accidentally use it
  iface_->setConnectionContext(nullptr);
  Raiser_doRaise_pargs args;
  std::unique_ptr<apache::thrift::ContextStack> ctxStack(this->getContextStack(this->getServiceName(), "Raiser.doRaise", ctx));
  try {
    deserializeRequest(args, buf.get(), iprot.get(), ctxStack.get());
  }
  catch (const std::exception& ex) {
    apache::thrift::detail::ap::process_handle_exn_deserialization<ProtocolOut_>(
        ex, std::move(req), ctx, eb, "doRaise");
    return;
  }
  req->setStartedProcessing();
  auto callback = std::make_unique<apache::thrift::HandlerCallback<void>>(std::move(req), std::move(ctxStack), return_doRaise<ProtocolIn_,ProtocolOut_>, throw_wrapped_doRaise<ProtocolIn_, ProtocolOut_>, ctx->getProtoSeqId(), eb, tm, ctx);
  if (!callback->isRequestActive()) {
    callback.release()->deleteInThread();
    return;
  }
  ctx->setStartedProcessing();
  iface_->async_tm_doRaise(std::move(callback));
}

template <class ProtocolIn_, class ProtocolOut_>
folly::IOBufQueue RaiserAsyncProcessor::return_doRaise(int32_t protoSeqId, apache::thrift::ContextStack* ctx) {
  ProtocolOut_ prot;
  Raiser_doRaise_presult result;
  return serializeResponse("doRaise", &prot, protoSeqId, ctx, result);
}

template <class ProtocolIn_, class ProtocolOut_>
void RaiserAsyncProcessor::throw_wrapped_doRaise(std::unique_ptr<apache::thrift::ResponseChannelRequest> req,int32_t protoSeqId,apache::thrift::ContextStack* ctx,folly::exception_wrapper ew,apache::thrift::Cpp2RequestContext* reqCtx) {
  if (!ew) {
    return;
  }
  Raiser_doRaise_presult result;
  if (ew.with_exception([&]( ::cpp2::Banal& e) {
    ctx->userExceptionWrapped(true, ew);
    result.get<0>().ref() = e;
    result.setIsSet(0, true);
  }
  )) {} else
  if (ew.with_exception([&]( ::cpp2::Fiery& e) {
    ctx->userExceptionWrapped(true, ew);
    result.get<1>().ref() = e;
    result.setIsSet(1, true);
  }
  )) {} else
  if (ew.with_exception([&]( ::cpp2::Serious& e) {
    ctx->userExceptionWrapped(true, ew);
    result.get<2>().ref() = e;
    result.setIsSet(2, true);
  }
  )) {} else
  {
    (void)protoSeqId;
    apache::thrift::detail::ap::process_throw_wrapped_handler_error<ProtocolOut_>(
        ew, std::move(req), reqCtx, ctx, "doRaise");
    return;
  }
  ProtocolOut_ prot;
  auto queue = serializeResponse("doRaise", &prot, protoSeqId, ctx, result);
  queue.append(apache::thrift::transport::THeader::transform(queue.move(), reqCtx->getHeader()->getWriteTransforms(), reqCtx->getHeader()->getMinCompressBytes()));
  return req->sendReply(queue.move());
}

template <typename ProtocolIn_, typename ProtocolOut_>
void RaiserAsyncProcessor::_processInThread_get200(std::unique_ptr<apache::thrift::ResponseChannelRequest> req, std::unique_ptr<folly::IOBuf> buf, std::unique_ptr<ProtocolIn_> iprot, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) {
  auto pri = iface_->getRequestPriority(ctx, apache::thrift::concurrency::NORMAL);
  processInThread<ProtocolIn_, ProtocolOut_>(std::move(req), std::move(buf),std::move(iprot), ctx, eb, tm, pri, apache::thrift::RpcKind::SINGLE_REQUEST_SINGLE_RESPONSE, &RaiserAsyncProcessor::process_get200<ProtocolIn_, ProtocolOut_>, this);
}
template <typename ProtocolIn_, typename ProtocolOut_>
void RaiserAsyncProcessor::process_get200(std::unique_ptr<apache::thrift::ResponseChannelRequest> req, std::unique_ptr<folly::IOBuf> buf, std::unique_ptr<ProtocolIn_> iprot,apache::thrift::Cpp2RequestContext* ctx,folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) {
  // make sure getConnectionContext is null
  // so async calls don't accidentally use it
  iface_->setConnectionContext(nullptr);
  Raiser_get200_pargs args;
  std::unique_ptr<apache::thrift::ContextStack> ctxStack(this->getContextStack(this->getServiceName(), "Raiser.get200", ctx));
  try {
    deserializeRequest(args, buf.get(), iprot.get(), ctxStack.get());
  }
  catch (const std::exception& ex) {
    apache::thrift::detail::ap::process_handle_exn_deserialization<ProtocolOut_>(
        ex, std::move(req), ctx, eb, "get200");
    return;
  }
  req->setStartedProcessing();
  auto callback = std::make_unique<apache::thrift::HandlerCallback<std::unique_ptr<std::string>>>(std::move(req), std::move(ctxStack), return_get200<ProtocolIn_,ProtocolOut_>, throw_wrapped_get200<ProtocolIn_, ProtocolOut_>, ctx->getProtoSeqId(), eb, tm, ctx);
  if (!callback->isRequestActive()) {
    callback.release()->deleteInThread();
    return;
  }
  ctx->setStartedProcessing();
  iface_->async_tm_get200(std::move(callback));
}

template <class ProtocolIn_, class ProtocolOut_>
folly::IOBufQueue RaiserAsyncProcessor::return_get200(int32_t protoSeqId, apache::thrift::ContextStack* ctx, std::string const& _return) {
  ProtocolOut_ prot;
  Raiser_get200_presult result;
  result.get<0>().value = const_cast<std::string*>(&_return);
  result.setIsSet(0, true);
  return serializeResponse("get200", &prot, protoSeqId, ctx, result);
}

template <class ProtocolIn_, class ProtocolOut_>
void RaiserAsyncProcessor::throw_wrapped_get200(std::unique_ptr<apache::thrift::ResponseChannelRequest> req,int32_t protoSeqId,apache::thrift::ContextStack* ctx,folly::exception_wrapper ew,apache::thrift::Cpp2RequestContext* reqCtx) {
  if (!ew) {
    return;
  }
  {
    (void)protoSeqId;
    apache::thrift::detail::ap::process_throw_wrapped_handler_error<ProtocolOut_>(
        ew, std::move(req), reqCtx, ctx, "get200");
    return;
  }
}

template <typename ProtocolIn_, typename ProtocolOut_>
void RaiserAsyncProcessor::_processInThread_get500(std::unique_ptr<apache::thrift::ResponseChannelRequest> req, std::unique_ptr<folly::IOBuf> buf, std::unique_ptr<ProtocolIn_> iprot, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) {
  auto pri = iface_->getRequestPriority(ctx, apache::thrift::concurrency::NORMAL);
  processInThread<ProtocolIn_, ProtocolOut_>(std::move(req), std::move(buf),std::move(iprot), ctx, eb, tm, pri, apache::thrift::RpcKind::SINGLE_REQUEST_SINGLE_RESPONSE, &RaiserAsyncProcessor::process_get500<ProtocolIn_, ProtocolOut_>, this);
}
template <typename ProtocolIn_, typename ProtocolOut_>
void RaiserAsyncProcessor::process_get500(std::unique_ptr<apache::thrift::ResponseChannelRequest> req, std::unique_ptr<folly::IOBuf> buf, std::unique_ptr<ProtocolIn_> iprot,apache::thrift::Cpp2RequestContext* ctx,folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) {
  // make sure getConnectionContext is null
  // so async calls don't accidentally use it
  iface_->setConnectionContext(nullptr);
  Raiser_get500_pargs args;
  std::unique_ptr<apache::thrift::ContextStack> ctxStack(this->getContextStack(this->getServiceName(), "Raiser.get500", ctx));
  try {
    deserializeRequest(args, buf.get(), iprot.get(), ctxStack.get());
  }
  catch (const std::exception& ex) {
    apache::thrift::detail::ap::process_handle_exn_deserialization<ProtocolOut_>(
        ex, std::move(req), ctx, eb, "get500");
    return;
  }
  req->setStartedProcessing();
  auto callback = std::make_unique<apache::thrift::HandlerCallback<std::unique_ptr<std::string>>>(std::move(req), std::move(ctxStack), return_get500<ProtocolIn_,ProtocolOut_>, throw_wrapped_get500<ProtocolIn_, ProtocolOut_>, ctx->getProtoSeqId(), eb, tm, ctx);
  if (!callback->isRequestActive()) {
    callback.release()->deleteInThread();
    return;
  }
  ctx->setStartedProcessing();
  iface_->async_tm_get500(std::move(callback));
}

template <class ProtocolIn_, class ProtocolOut_>
folly::IOBufQueue RaiserAsyncProcessor::return_get500(int32_t protoSeqId, apache::thrift::ContextStack* ctx, std::string const& _return) {
  ProtocolOut_ prot;
  Raiser_get500_presult result;
  result.get<0>().value = const_cast<std::string*>(&_return);
  result.setIsSet(0, true);
  return serializeResponse("get500", &prot, protoSeqId, ctx, result);
}

template <class ProtocolIn_, class ProtocolOut_>
void RaiserAsyncProcessor::throw_wrapped_get500(std::unique_ptr<apache::thrift::ResponseChannelRequest> req,int32_t protoSeqId,apache::thrift::ContextStack* ctx,folly::exception_wrapper ew,apache::thrift::Cpp2RequestContext* reqCtx) {
  if (!ew) {
    return;
  }
  Raiser_get500_presult result;
  if (ew.with_exception([&]( ::cpp2::Fiery& e) {
    ctx->userExceptionWrapped(true, ew);
    result.get<1>().ref() = e;
    result.setIsSet(1, true);
  }
  )) {} else
  if (ew.with_exception([&]( ::cpp2::Banal& e) {
    ctx->userExceptionWrapped(true, ew);
    result.get<2>().ref() = e;
    result.setIsSet(2, true);
  }
  )) {} else
  if (ew.with_exception([&]( ::cpp2::Serious& e) {
    ctx->userExceptionWrapped(true, ew);
    result.get<3>().ref() = e;
    result.setIsSet(3, true);
  }
  )) {} else
  {
    (void)protoSeqId;
    apache::thrift::detail::ap::process_throw_wrapped_handler_error<ProtocolOut_>(
        ew, std::move(req), reqCtx, ctx, "get500");
    return;
  }
  ProtocolOut_ prot;
  auto queue = serializeResponse("get500", &prot, protoSeqId, ctx, result);
  queue.append(apache::thrift::transport::THeader::transform(queue.move(), reqCtx->getHeader()->getWriteTransforms(), reqCtx->getHeader()->getMinCompressBytes()));
  return req->sendReply(queue.move());
}

} // cpp2
namespace apache { namespace thrift {

}} // apache::thrift
