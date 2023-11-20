// File Line: 190
// RVA: 0x7F8070
bool __fastcall Scaleform::GFx::AS3::Multiname::IsAnyNamespace(Scaleform::GFx::AS3::Multiname *this)
{
  return (this->Kind & 3u) <= 1 && !this->Obj.pObject;
}

// File Line: 287
// RVA: 0x781650
void __fastcall Scaleform::GFx::AS3::PropRef::PropRef(Scaleform::GFx::AS3::PropRef *this, Scaleform::GFx::AS3::Value *_this, Scaleform::GFx::AS3::SlotInfo *si, unsigned __int64 index)
{
  signed int v4; // eax
  long double v5; // rcx

  this->pSI = si;
  this->SlotIndex = index;
  this->This.Flags = _this->Flags;
  this->This.Bonus.pWeakProxy = _this->Bonus.pWeakProxy;
  this->This.value = _this->value;
  v4 = _this->Flags & 0x1F;
  if ( v4 > 9 )
  {
    if ( (_this->Flags >> 9) & 1 )
    {
      ++_this->Bonus.pWeakProxy->RefCount;
      return;
    }
    if ( v4 == 10 )
    {
      ++*(_DWORD *)(*(_QWORD *)&_this->value.VNumber + 24i64);
    }
    else
    {
      if ( v4 <= 10 )
        return;
      if ( v4 <= 15 )
      {
        v5 = _this->value.VNumber;
      }
      else
      {
        if ( v4 > 17 )
          return;
        v5 = *(double *)&_this->value.VS._2.VObj;
      }
      if ( v5 != 0.0 )
        *(_DWORD *)(*(_QWORD *)&v5 + 32i64) = (*(_DWORD *)(*(_QWORD *)&v5 + 32i64) + 1) & 0x8FBFFFFF;
    }
  }
}

// File Line: 312
// RVA: 0x790D50
bool __fastcall Scaleform::GFx::AS3::PropRef::operator bool(Scaleform::GFx::AS3::PropRef *this)
{
  return this->This.Flags & 0x1F
      && (!((_QWORD)this->pSI & 1) || (_QWORD)this->pSI & 0xFFFFFFFFFFFFFFFEui64)
      && (!(((unsigned __int8)this->pSI >> 1) & 1) || (_QWORD)this->pSI & 0xFFFFFFFFFFFFFFFDui64);
}

