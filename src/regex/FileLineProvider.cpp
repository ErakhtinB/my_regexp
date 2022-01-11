#include "FileLineProvider.h"
#include <stdexcept>

namespace regex {

FileLineProvider::FileLineProvider(const char* filePath)
    : m_is(filePath ? filePath : throw std::invalid_argument("File path empty"))
{
    if (m_is.fail())
    {
        throw std::runtime_error(std::string("Failed to open file ")
            + filePath);
    }
}

std::optional<std::string> FileLineProvider::GetNextLine()
{
    std::string line;
    if (std::getline(m_is, line))
    {
        return line;
    }
    return {};
}

} // namespace regex
