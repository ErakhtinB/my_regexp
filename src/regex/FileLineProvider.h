#include "LineProvider.h"

namespace regex {

struct FileLineProvider : public line_provider::ILineProvider
{
    FileLineProvider(const char* filePath);
    std::optional<std::string> GetNextLine() override;
private:
    const char* const m_filePath;
};

} // namespace regex
