#include "LineProvider.h"
#include <fstream>

namespace regex {

struct FileLineProvider : public line_provider::ILineProvider
{
    FileLineProvider(const char* filePath);
    std::optional<std::string> GetNextLine() override;
private:
    std::ifstream m_is;
};

} // namespace regex
