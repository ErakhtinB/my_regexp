#include <memory>
#include <ostream>

#include "LineProvider.h"

namespace regex
{

struct ParseResult
{
    enum struct MaskType
    {
        AsteriskLeft,
        AsteriskRight,
        AsteriskBothSide,
        Strict,
        QuestionLeft,
        QuestionRight,
        QuestionBothSide,
        Error
    };
    MaskType maskType;
    std::string stringToBeFound;
};

void Match(std::shared_ptr<line_provider::ILineProvider> lineProvider,
    const std::string& mask,
    std::ostream& os);

ParseResult ParseMask(const std::string& mask);

} // namespace regex
