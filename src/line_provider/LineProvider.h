#ifndef LINE_PROVIDER_H
#define LINE_PROVIDER_H

#include <optional>
#include <string>

namespace line_provider {

struct ILineProvider
{
    virtual std::optional<std::string> GetNextLine() = 0;
    virtual ~ILineProvider() = default;
};

} // namespace line_provider

#endif // LINE_PROVIDER_H
