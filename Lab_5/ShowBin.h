///////////////////////////////////////////////////////////
// ShowBin.h
#include "Action.h"

// Операция отображения бинарного значения (для HEX)
class ShowBin : public Action {
public:
    ShowBin() : name("Show binary value") {}
    void Operate(AString*) override;
    const std::string& GetName() const override { return name; }

private:
    std::string GetBinary(AString*) const; // Вспомогательный метод
    std::string name;
};

extern ShowBin show_bin; // Глобальный объект
///////////////////////////////////////////////////////////