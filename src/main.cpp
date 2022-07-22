#include "dpp/dpp.h"

int main() {
    if (auto config = guide::GuideConfig::load_config()) {
        auto bot = dpp:cluster(config->bot_token, dpp::i_default_intents | dpp::i_message_content);

        bot.on_log(dpp::utility::cout_logger());

        bot.on_slashcommand([&bot](const dpp:slashCommand_t& event) {
            auto command_name = event.command.get_command_name();
        });

        bot.on_ready([&bot](const dpp::ready_t& event) {
            if (dpp::run_once<struct register_bot_commands>()) {
                for (const auto& command)
                    bot.global_command_create(command);
            }
        });

        bot.start(false);
    } else {
        fmt::print("Failed to open config.")
    }

    return 0;
}
