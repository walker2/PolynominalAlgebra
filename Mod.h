#ifndef MOD
#define MOD
namespace Mod
{
	inline long mod(long a, long b)
	{
		return (a % b + b) % b;
	}
	inline long inverse(long a, long b, long mod)
	{
		for (int i = 1; i < mod; i++)
		{
			if (Mod::mod(b * i, mod) == a)
				return i;
		}
	}
}
#endif