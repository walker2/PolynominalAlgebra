#include "Polynom.h"



Polynom::Polynom()
	:data(), field(0)
{
}

Polynom::Polynom(int size, int f)
	:data(), field(f)
{
	while (size)
	{
		size--;
		data.push_back(0);
	}
}

Polynom::Polynom(std::string polynom, int f)
	:data(), field(f)
{
	std::istringstream iss(polynom);
	std::string token;
	while (std::getline(iss, token, ' '))
	{
		if (field)
			data.push_back(Mod::mod(std::atoi(token.c_str()), field));
		else
			data.push_back(std::atoi(token.c_str()));
	}
}

Polynom::Polynom(std::vector<int>& v, int f)
{
	field = f;
	data = v;
}

Polynom::Polynom(const Polynom& p)
{
	data.clear();
	remainder = p.remainder;
	field = p.field;
	data = p.data;
}

Polynom::~Polynom()
{
}

Polynom& Polynom::operator=(const Polynom& p)
{
	remainder = p.remainder;
	field = p.field;
	data = p.data;
	return *this;
}

Polynom Polynom::operator+(const Polynom& p)
{
	std::vector<int>::const_iterator p_iter;
	for (iter = data.begin(), p_iter = p.data.begin(); iter != data.end() && p_iter != p.data.end(); iter++, p_iter++)
	{
		if (field)
			(*iter) = Mod::mod(((*iter) + (*p_iter)), field);
		else
			(*iter) = ((*iter) + (*p_iter));
	}

	return *this;
}

Polynom Polynom::operator-(Polynom & p)
{
	for (iter = data.begin(), p.iter = p.data.begin(); iter != data.end() && p.iter != p.data.end(); iter++, p.iter++)
	{
		if (field)
			(*iter) = Mod::mod(((*iter) - (*p.iter)), field);
		else
			(*iter) = ((*iter) - (*p.iter));
	}

	return *this;
}


Polynom Polynom::operator*(Polynom & p)
{
	Polynom result(data.size() + p.data.size(), p.field);

	for (int i = 0; i < data.size(); i++)
	{
		for (int j = 0; j < p.data.size(); j++)
		{
 			if(field)
				result.data[i + j] = Mod::mod(result.data[i + j] + (data[i] * p.data[j]), field);
			else
				result.data[i + j] = result.data[i + j] + (data[i] * p.data[j]);
		}
	}

	
	return result;
}

Polynom Polynom::operator/(Polynom & p)
{
	Polynom substract(data.size());
	Polynom result(data.size() + p.data.size());
	Polynom dividend(*this);
	Polynom divider(p);
	int i = 0;
	while (dividend.data.size() - divider.data.size() - i + 1 > 0)
	{
		Polynom tmp_res(data.size() + p.data.size());
		if (field)
		{
			tmp_res.data[dividend.data.size() - divider.data.size() - i] = Mod::inverse((dividend.data[dividend.data.size() - i - 1]) , divider.data.back(), field);
		}
		else
		{
			tmp_res.data[dividend.data.size() - divider.data.size() - i] = (dividend.data[dividend.data.size() - i - 1]) / divider.data.back();
		}

		result = result + tmp_res;
		std::cout << dividend;
		substract = tmp_res * divider;
		std::cout << substract;
		dividend = dividend - substract;
		i++;
	}
	std::cout << dividend;
	result.remainder = dividend.data;
	result.setField(p.getField());
	
	return result;
}

Polynom& Polynom::undefinedCoef(Polynom & divider)
{
	*this = *this / divider;
	return *this;
}

std::ostream& operator<<(std::ostream & o, Polynom & p)
{
	for (p.iter = p.data.begin(); p.iter != p.data.end(); p.iter++)
	{
		if ((*p.iter) != 0)
		{
			if ((*p.iter) > 0 && p.iter != p.data.begin())
				o << '+' << (*p.iter) << "x^" << p.iter - p.data.begin();
			else
				o << (*p.iter) << "x^" << p.iter - p.data.begin();
		}
	}
	o << std::endl;

	if (p.remainder.size())
	{
		std::cout << "REMAINDER: ";
		for (p.iter = p.remainder.begin(); p.iter != p.remainder.end(); p.iter++)
		{
			if ((*p.iter) != 0)
			{
				if ((*p.iter) > 0 && (*p.iter) != p.remainder.front())
					o << '+' << (*p.iter) << "x^" << p.iter - p.remainder.begin();
				else
					o << (*p.iter) << "x^" << p.iter - p.remainder.begin();
			}
		}
	}
	o << std::endl;

	return o;
}

void Polynom::shift(int num)
{
    auto prevData = data;
    data.resize(prevData.size() + num);
	for (int i = 0; i < data.size() + num; i++)
	{
		if (i < num)
		{
			data[i] = 0;
		} else
		{
			data[i] = prevData[i - num];
		}
	}
}

bool Polynom::isZero()
{
    for (int i = 0; i < data.size(); i++)
    {
        if (data[i] != 0)
            return false;
    }
    return true;
}
