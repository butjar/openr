/**
 * Copyright (c) 2014-present, Facebook, Inc.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#pragma once

#include <memory>
#include <string>

#include <wangle/ssl/SSLContextConfig.h>

#include <openr/common/Types.h>
#include <openr/config/Config.h>
#include <openr/if/gen-cpp2/Fib_types.h>
#include <openr/if/gen-cpp2/PrefixManager_types.h>
#include <openr/messaging/Queue.h>
#include <openr/messaging/ReplicateQueue.h>

namespace openr {
struct PluginArgs {
  messaging::ReplicateQueue<thrift::PrefixUpdateRequest>& prefixUpdatesQueue;
  messaging::ReplicateQueue<openr::thrift::RouteDatabaseDelta>&
      staticRoutesUpdateQueue;
  messaging::RQueue<thrift::RouteDatabaseDelta> routeUpdatesQueue;
  std::shared_ptr<const Config> config;
  std::shared_ptr<wangle::SSLContextConfig> sslContext;
};

void pluginStart(const PluginArgs& /* pluginArgs */);
void pluginStop();
} // namespace openr
