#ifndef GUIDE_COMMANDS
#define GUIDE_COMMANDS

#include <array>
#include <chrono>
#include <map>
#include <string>

#include "dpp/dpp.h"
#include "re2/re2.h"

namespace guide {
    namespace commands {
        namespace slash {
            extern const re2::RE2 time_range_exp;

            using handler = std::function<void(const dpp::slashcommand_t &)>;
            using handler_map = std::unordered_map<std::string, handler>;
            static handler_map handlers;
            
            using commands_array = std::array<dpp::slashcommand, 2>;
            extern commands_array commands;
        };

        using time_jump_map = std::map<char, size_t>;
        using optional_time_jump_map = std::optional<time_jump_map>;

        inline optional_time_jump_map parse_jump_time(const std::string &);

        void init_guide(dpp::cluster &bot);
        void handle_slash_command(const std::string &command_name, const dpp::slashcommand_t &event);
    };
};

#endif /* GUIDE_COMMANDS */
