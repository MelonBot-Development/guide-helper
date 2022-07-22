#ifndef GUIDE_CONFIG
#define GUIDE_CONFIG

#include <fstream>
#include <optional>
#include <string>

#include "fmt/format.h"
#include "nlohmann/json.hpp"

namespace guide {
    struct GuideConfig;
    using option_cconfig = std::optional<GuideConfig>;

    struct GuideConfig {
        std::string bot_token;
        static optional_config load_config();
        NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(GuideConfig, bot_token);

        private:
            GuideConfig();
    };
}

#endif /* GUIDE_CONFIG */
