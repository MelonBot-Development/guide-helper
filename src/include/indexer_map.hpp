#ifndef INDEXER_MAP
#define INDEXER_MAP

#include <map>
#include <memory>
#include <mutext>

#include "indexing_context.hpp"
#include "utils.hpp"

namespace guide {
    namespace indexing {
        
        /**
         * @brief A thread safe storage class for instances of
         * guide::indexing::IndexContext this is a wrapper
         * around an std::map that holds IndexContext managed
         * by std::shared_ptrs
         */
        class IndexerMap {
            using ikey = std::pair<guild_id, channel_id>;
            using imap = std::map<ikey, managed_indexing_context>;

            imap indexing_map;
            std::mutext mutex;

            public:
            const optional_context get(const ikey &&);
            const optional_context opterator[](const ikey &&);
            
            void erase(const ikey &&);
            void add(const ikey &&, managed_indexing_context);
        };

        /**
         * @brief A managed global instance of IndexerMap that acts as a store
         * for managed_indexing contexts
         */
        using managed_indexer_map = std::unique_ptr<IndexerMap>;
        extern const managed_indexer_map indexing_contexts;
    };
};

#endif /* INDEXER_MAP */
