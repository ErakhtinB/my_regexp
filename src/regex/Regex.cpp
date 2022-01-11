#include "Regex.h"
#include <string>

namespace regex {

static ParseResult ParseForAsteriks(const std::string& mask, std::size_t asteriks);
static ParseResult ParseForQuest(const std::string& mask, std::size_t quest);

void Match(std::shared_ptr<line_provider::ILineProvider> lineProvider,
    const std::string& mask, std::ostream& os)
{
    throw std::runtime_error("Not implemented");
}

ParseResult ParseMask(const std::string &mask)
{
    auto asteriks = mask.find('*');
    auto quest = mask.find('?');
    if (asteriks != std::string::npos)
    {
        if (quest != std::string::npos)
        {
            return {ParseResult::MaskType::Error, ""};
        }
        return ParseForAsteriks(mask, asteriks);
    }
    else if (quest != std::string::npos)
    {
        if (asteriks != std::string::npos)
        {
            return {ParseResult::MaskType::Error, ""};
        }
        return ParseForQuest(mask, quest);
    }
    return {ParseResult::MaskType::Strict, mask};
}

ParseResult ParseForAsteriks(const std::string& mask, std::size_t asteriks)
{
    if (asteriks == 0)
    {
        while (mask[++asteriks] == '*');
        if (asteriks == mask.size())
        {
            return {ParseResult::MaskType::Error, ""};
        }
        else
        {
            if (auto anotherAsteriks = mask.find('*', asteriks); anotherAsteriks == std::string::npos)
            {
                return {ParseResult::MaskType::AsteriskLeft, mask.substr(asteriks)};
            }
            else
            {
                auto s = mask.substr(asteriks, anotherAsteriks - asteriks);
                while (++anotherAsteriks < mask.size())
                {
                    if (mask[anotherAsteriks] != '*')
                    {
                        return {ParseResult::MaskType::Error, ""};
                    }
                }
                return {ParseResult::MaskType::AsteriskBothSide, s};
            }
        }
    }
    else
    {
        auto anotherAsteriks = asteriks;
        while (asteriks != mask.size())
        {
            if (mask[asteriks++] == '*')
            {
                continue;
            }
            else
            {
                return {ParseResult::MaskType::Error, ""};
            }
        }
        return {ParseResult::MaskType::AsteriskRight, mask.substr(0, anotherAsteriks)};
    }
}

ParseResult ParseForQuest(const std::string& mask, std::size_t quest)
{
    if (quest == 0)
    {
        if (mask[++quest] == '?' || mask.size() == 1)
        {
            return {ParseResult::MaskType::Error, ""};
        }
        auto anotherQuest = mask.find('?', quest);
        if (anotherQuest != std::string::npos)
        {
            if (mask[anotherQuest + 1] != '?')
            {
                return {ParseResult::MaskType::QuestionBothSide, mask.substr(quest, anotherQuest - 1)};
            }
            return {ParseResult::MaskType::Error, ""};
        }
        return {ParseResult::MaskType::QuestionLeft, mask.substr(quest)};
    }
    else
    {
        if (quest != mask.size() - 1)
        {
            return {ParseResult::MaskType::Error, ""};
        }
        return {ParseResult::MaskType::QuestionRight, mask.substr(0, quest)};
    }
}

} // namespace regex
