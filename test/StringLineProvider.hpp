#include "LineProvider.h"
#include <vector>

namespace {

struct StringLineProvider : public line_provider::ILineProvider
{
    StringLineProvider(const std::vector<std::string>& v)
        : m_index(0)
        , m_lines(v) {}
    std::optional<std::string> GetNextLine() override
    {
        if (m_index < m_lines.size())
        {
            return m_lines[m_index++];
        }
        return {};
    }
private:
    std::size_t m_index;
    const std::vector<std::string> m_lines;
};

} // namespace
