// File Line: 112
// RVA: 0x49230
UFG::qString *__fastcall UFG::qString::operator=(UFG::qString *this, UFG::qString *text)
{
  UFG::qString::Set(this, text->mData, text->mLength, 0i64, 0);
  return this;
}

// File Line: 113
// RVA: 0x69DE0
UFG::qString *__fastcall UFG::qString::operator=(UFG::qString *this, const char *text)
{
  UFG::qString::Set(this, text);
  return this;
}

// File Line: 118
// RVA: 0x141980
UFG::qString *__fastcall UFG::operator+(UFG::qString *result, UFG::qString *lhs, UFG::qString *rhs)
{
  UFG::qString *v5; // rax
  UFG::qString v7; // [rsp+30h] [rbp-38h] BYREF

  UFG::qString::qString(&v7, lhs);
  v5 = UFG::qString::operator+=(&v7, rhs);
  UFG::qString::qString(result, v5);
  UFG::qString::~qString(&v7);
  return result;
}

// File Line: 119
// RVA: 0x1419F0
UFG::qString *__fastcall UFG::operator+(UFG::qString *result, UFG::qString *lhs, const char *rhs)
{
  UFG::qString *v5; // rax
  UFG::qString v7; // [rsp+30h] [rbp-38h] BYREF

  UFG::qString::qString(&v7, lhs);
  v5 = UFG::qString::operator+=(&v7, rhs);
  UFG::qString::qString(result, v5);
  UFG::qString::~qString(&v7);
  return result;
}

// File Line: 120
// RVA: 0x164BB0
UFG::qString *__fastcall UFG::operator+(UFG::qString *result, const char *lhs, UFG::qString *rhs)
{
  UFG::qNode<UFG::qString,UFG::qString> *mPrev; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *mNext; // rax
  UFG::qString v8; // [rsp+40h] [rbp-38h] BYREF

  UFG::qString::qString(&v8, lhs);
  if ( rhs->mLength )
    UFG::qString::Set(&v8, v8.mData, v8.mLength, rhs->mData, rhs->mLength);
  result->mPrev = result;
  result->mNext = result;
  result->mMagic = 16909060;
  result->mData = (char *)UFG::qString::sEmptyString;
  result->mLength = 0;
  UFG::qString::Set(result, v8.mData, v8.mLength, 0i64, 0);
  result->mStringHash32 = v8.mStringHash32;
  result->mStringHashUpper32 = v8.mStringHashUpper32;
  if ( v8.mData != UFG::qString::sEmptyString && v8.mData )
    UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v8.mData);
  mPrev = v8.mPrev;
  mNext = v8.mNext;
  v8.mPrev->mNext = v8.mNext;
  mNext->mPrev = mPrev;
  return result;
}

// File Line: 123
// RVA: 0x164BA0
__int64 __fastcall UFG::qString::operator[](UFG::qString *this, int pos)
{
  return (unsigned __int8)this->mData[pos];
}

// File Line: 155
// RVA: 0x81CA0
__int64 __fastcall hkaMatrix<float>::Width(hkaMatrix<float> *this)
{
  return (unsigned int)this->m_n;
}

// File Line: 156
// RVA: 0x51A50
_BOOL8 __fastcall UFG::qString::IsEmpty(UFG::qString *this)
{
  return this->mLength == 0;
}

// File Line: 223
// RVA: 0x3AE0
__int64 __fastcall UFG::qString::GetStringHashUpper32(UFG::qString *this)
{
  __int64 result; // rax

  if ( this->mStringHashUpper32 != -1 )
    return this->mStringHashUpper32;
  result = UFG::qStringHashUpper32(this->mData, 0xFFFFFFFF);
  this->mStringHashUpper32 = result;
  return result;
}

// File Line: 351
// RVA: 0x8C6C0
char *__fastcall UFG::qStringCopy(char *dest, const char *text)
{
  return UFG::qStringCopy(dest, 0x7FFFFFFF, text, -1);
}

// File Line: 575
// RVA: 0x1FF0
__int64 UFG::qPrintf(const char *format, ...)
{
  return 0i64;
}

