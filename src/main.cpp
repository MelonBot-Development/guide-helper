#include "dpp/dpp.h"
#include "include/config.hpp"
#include "include/gcommands.hpp"

int main() {
    if (auto config = guide::GuideConfig::load_config()) {
        auto bot = dpp:cluster(config->bot_token, dpp::i_default_intents | dpp::i_message_content);

        bot.on_log(dpp::utility::cout_logger());

        guide::commands::init_guide(bot);

        bot.on_slashcommand([&bot](const dpp:slashCommand_t& event) {
            auto command_name = event.command.get_command_name();
            guide::commands::handle_slash_command(command_name, event);
        });

        bot.on_ready([&bot](const dpp::ready_t& event) {
            if (dpp::run_once<struct register_bot_commands>()) {
                for (const auto& command : guide::commands::slash::commands)
                    bot.global_command_create(command);
            }
        });

        bot.start(false);
    } else {
        fmt::print("Failed to open config.")
    }

    return 0;
}
