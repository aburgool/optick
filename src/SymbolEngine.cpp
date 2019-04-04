#include "optick.config.h"

#if USE_OPTICK

#include "SymbolEngine.h"

namespace Optick
{
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	OutputDataStream& operator<<(OutputDataStream& os, const Symbol * const symbol)
	{
		OPTICK_VERIFY(symbol, "Can't serialize NULL symbol!", return os);
		return os << symbol->address << symbol->function << symbol->file << symbol->line;
	}
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	OutputDataStream& operator<<(OutputDataStream& os, const Module& module)
	{
		return os << module.path << (uint64)module.address << (uint64)module.size;
	}
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	const Symbol* const SymbolEngine::GetSymbol(uint64 /*dwAddress*/)
	{
		return nullptr;
	}
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#if !OPTICK_ENABLE_SYMENGINE
    SymbolEngine* SymbolEngine::Get()
    {
		static SymbolEngine pdbSymbolEngine;
		return &pdbSymbolEngine;
    }
#endif
}

#endif //USE_OPTICK