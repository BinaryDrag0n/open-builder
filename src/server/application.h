#pragma once

#include <common/constants.h>
#include <vector>

#include "network/server.h"
#include "world/chunk/chunk.h"
#include "world/entity.h"

class LaunchConfig;

namespace server {
    class Application final {
      public:
        Application(const LaunchConfig &config, port_t port);

        void run(sf::Time timeout);

      private:
        void update(sf::Time deltaTime);
        void sendState();

        EntityArray m_entities;
        Server m_server;

        bool m_isRunning = true;

        std::vector<Chunk> m_chunks;
    };
} // namespace server
