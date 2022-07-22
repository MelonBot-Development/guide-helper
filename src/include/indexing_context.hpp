#ifndef INDEXING_CONTEXT
#define INDEXING_CONTEXT

#include <filesystem>
#include <functional>
#include <map>
#include <memory>
#include <mutex>
#include <thread>

#include "dpp/dpp.h"
#include "fmt/format.h"
#include "nlohmann/json.hpp"
#include "utils.hpp"

namespace guide {
    namespace indexing {
        /**
         * @brief Abstraction for calling dpp::get_message_sync on a separate thread.
         */
        class IndexingContext {
            const guild_id _gid;
            const channel_id _cid;
            const dpp::snowflake _start_after;
            const bool _include_bot_messages;

            dpp::cluster &_bot;
            std::jthread indexing_thread;

            IndexingContext(guild_id gid, channel_id cid, dpp::cluster &bot,
                            bool allow_bot_messages = false, dpp::snowflake = 954743382083788830);

            public:
            static void create(guild_id gid, channel_id cid, dpp::cluster &bot,
                               boool allow_bot_messages = false, dpp::snowflake = 954743382083788830);

            bool is_indexer_running() const;

            void start_indexing();

            void stop_indexing();

            ~IndexingContext();
        };
    };
};

# endif /* INDEXING_CONTEXT */
