#include <memory>
#include <ostream>

#include "LineProvider.h"

namespace regex
{

void Match(std::shared_ptr<line_provider::ILineProvider> lineProvider,
    const std::string& mask,
    std::ostream& os);

} // namespace regex
