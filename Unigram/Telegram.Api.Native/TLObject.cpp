#include "pch.h"
#include "TLObject.h"

using namespace Telegram::Api::Native;
using namespace Telegram::Api::Native::TL;

std::unordered_map<UINT32, TLObject::TLObjectConstructor> TLObject::s_constructors = std::unordered_map<UINT32, TLObject::TLObjectConstructor>();

HRESULT TLObject::Read(ITLBinaryReader* reader)
{
	if (reader == nullptr)
	{
		return E_POINTER;
	}

	return Read(static_cast<ITLBinaryReaderEx*>(reader));
}

HRESULT TLObject::Write(ITLBinaryWriter* writer)
{
	if (writer == nullptr)
	{
		return E_POINTER;
	}

	return Write(static_cast<ITLBinaryWriterEx*>(writer));
}

HRESULT TLObject::Deserialize(ITLBinaryReaderEx* reader, UINT32 constructor, ITLObject** object)
{
	if (reader == nullptr || object == nullptr)
	{
		return E_POINTER;
	}

	auto objectConstructor = s_constructors.find(constructor);
	if (objectConstructor == s_constructors.end())
	{
		return E_INVALIDARG;
	}

	return objectConstructor->second(object);
}