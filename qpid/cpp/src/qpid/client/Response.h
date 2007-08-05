/*
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
 */

#ifndef _Response_
#define _Response_

#include <boost/shared_ptr.hpp>
#include "qpid/framing/amqp_framing.h"
#include "FutureResponse.h"

namespace qpid {
namespace client {

class Response
{
    boost::shared_ptr<FutureResponse> future;

public:
    Response(boost::shared_ptr<FutureResponse> f) : future(f) {}

    template <class T> T& as() 
    {
        framing::AMQMethodBody::shared_ptr response(future->getResponse());
        return boost::shared_polymorphic_cast<T>(*response);
    }
    template <class T> bool isA() 
    {
        return future->getResponse()->isA<T>();
    }
    
    void sync()
    {
        return future->waitForCompletion();
    }

    //TODO: only exposed for old channel class, may want to hide this eventually
    framing::AMQMethodBody::shared_ptr getPtr()
    {
        return future->getResponse();
    }
};

}}

#endif
