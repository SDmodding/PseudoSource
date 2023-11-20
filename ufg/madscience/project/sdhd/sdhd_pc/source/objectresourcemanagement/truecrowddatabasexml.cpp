// File Line: 82
// RVA: 0x43F0A0
UFG::TrueCrowdDataBase *__fastcall UFG::TrueCrowdDataBase::Instance()
{
  return UFG::TrueCrowdDataBase::sTrueCrowdDataBase;
}

// File Line: 151
// RVA: 0x43DD30
void __fastcall UFG::TrueCrowdResource::GetPath(UFG::TrueCrowdResource *this, char *string, int length)
{
  unsigned int v3; // er9
  int v4; // er9
  char *v5; // r9

  v3 = this->mType.mValue;
  if ( v3 )
  {
    v4 = v3 - 1;
    if ( v4 )
    {
      if ( v4 == 1 )
      {
        if ( this->mName.mOffset )
          UFG::qSPrintf(string, length, "Data\\Props_New\\%s", (char *)this + this->mName.mOffset);
        else
          UFG::qSPrintf(string, length, "Data\\Props_New\\%s", 0i64);
      }
    }
    else if ( this->mName.mOffset )
    {
      UFG::qSPrintf(string, length, "Data\\Vehicles_New\\%s", (char *)this + this->mName.mOffset);
    }
    else
    {
      UFG::qSPrintf(string, length, "Data\\Vehicles_New\\%s", 0i64);
    }
  }
  else
  {
    if ( this->mName.mOffset )
      v5 = (char *)this + this->mName.mOffset;
    else
      v5 = 0i64;
    UFG::qSPrintf(string, length, "Data\\Characters_New\\%s", v5);
  }
}

