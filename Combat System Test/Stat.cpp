#include "Stat.h"

Stat::Stat()
{
    value = 3;
    buff = 3;
    debuff = 3;
}

Stat::Stat(int _value, int _buff, int _debuff, std::string _name) 
    : value(_value), buff(_buff), debuff(_debuff), name(_name)
{
}

Stat Stat::operator+(const Stat& _factor)
{
    value += _factor.value;
    buff += _factor.buff;
    debuff += _factor.debuff;

    return *this;
}

Stat Stat::operator-(const Stat& _factor)
{
    value -= _factor.value;
    buff -= _factor.buff;
    debuff -= _factor.debuff;

    return *this;
}

Stat Stat::operator*(const Stat& _factor)
{
    value *= _factor.value;
    buff *= _factor.buff;
    debuff *= _factor.debuff;

    return *this;
}

Stat Stat::operator/(const Stat& _factor)
{
    value /= _factor.value;
    buff /= _factor.buff;
    debuff /= _factor.debuff;

    return *this;
}

Stat Stat::operator=(const Stat& _factor)
{
    if (this != &_factor) {
        value = _factor.value;
        buff = _factor.buff;
        debuff = _factor.debuff;
    }
    return *this;
}

std::string Stat::GetName() const
{
    return name;
}

void Stat::SetName(std::string _name)
{
    name = _name;
}

int Stat::GetValue()
{
    return value;
}

void Stat::SetValue(int _value)
{
    value = _value;
}

void Stat::SetValue(float _value)
{
    value = (int)_value;

}

void Stat::IncreaseValue(int _value)
{
    value += _value;

}

void Stat::IncreaseValue(float _value)
{
    value += (int)_value;

}

void Stat::DereaseValue(int _value)
{
    value -= _value;
}

void Stat::DecreaseValue(float _value)
{
    value -= (int)_value;
}

int Stat::GetBuff()
{
    return buff;
}

void Stat::SetBuff(int _buff)
{
    buff = _buff;
    ApplyBuff();
}

void Stat::ApplyBuff()
{
    value += buff;
}

void Stat::RemoveBuff()
{
    value -= buff;
}

int Stat::GetDebuff()
{
    return debuff;
}

void Stat::SetDebuff(int _debuff)
{
    debuff = _debuff;
}

void Stat::ApplyDebuff()
{
    value -= debuff;
}

void Stat::RemoveDebuff()
{
    value += debuff;
}

void Stat::Display()
{
    std::cout << GetName() << ":\n";
    std::cout << "Value = " << GetValue();
    std::cout << "\tBuff = " << GetBuff();
    std::cout << "\tDebuff = " << GetDebuff() << "\n" << std::endl;
}
