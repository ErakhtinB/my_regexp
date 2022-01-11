#include "FileLineProvider.h"
#include <stdexcept>

namespace regex {

FileLineProvider::FileLineProvider(const char* filePath)
    : m_filePath(filePath ? filePath : throw std::invalid_argument("File path empty")) {}

std::optional<std::string> FileLineProvider::GetNextLine()
{
    throw std::runtime_error("Not implemented");
}

} // namespace regex
