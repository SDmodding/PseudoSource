// File Line: 58
// RVA: 0xB0580
void __fastcall UFG::qReflectString::Set(UFG::qReflectString *this, const char *value)
{
  unsigned int v4; // ebx

  v4 = UFG::qStringLength(value) + 1;
  UFG::qReflectArray<char>::Resize(&this->mText, v4, "qReflectString::Set()");
  UFG::qMemCopy(this->mText.mData.mItems, value, v4);
}

