#include "Regex.h"

namespace regex {

void Match(std::shared_ptr<line_provider::ILineProvider> lineProvider,
    const std::string& mask, std::ostream& os)
{
    throw std::runtime_error("Not implemented");
}

ParseResult ParseMask(const std::string &mask)
{
    throw std::runtime_error("Not implemented");
}

} // namespace regex
