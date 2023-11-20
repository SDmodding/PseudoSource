// File Line: 58
// RVA: 0xB0580
void __fastcall UFG::qReflectString::Set(UFG::qReflectString *this, const char *value)
{
  UFG::qReflectString *v2; // rsi
  const char *v3; // rdi
  unsigned int v4; // ebx

  v2 = this;
  v3 = value;
  v4 = (unsigned __int64)UFG::qStringLength(value) + 1;
  UFG::qReflectArray<char>::Resize(&v2->mText, v4, "qReflectString::Set()");
  UFG::qMemCopy(v2->mText.mData.mItems, v3, v4);
}

