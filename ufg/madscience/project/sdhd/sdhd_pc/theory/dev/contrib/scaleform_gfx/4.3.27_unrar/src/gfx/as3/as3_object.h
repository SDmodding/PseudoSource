// File Line: 190
// RVA: 0x7F8070
bool __fastcall Scaleform::GFx::AS3::Multiname::IsAnyNamespace(Scaleform::GFx::AS3::Multiname *this)
{
  return (this->Kind & 3u) <= 1 && !this->Obj.pObject;
}

// File Line: 287
// RVA: 0x781650
void __fastcall Scaleform::GFx::AS3::PropRef::PropRef(
        Scaleform::GFx::AS3::PropRef *this,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::SlotInfo *si,
        unsigned __int64 index)
{
  Scaleform::GFx::AS3::Value::V1U VObj; // rcx

  this->pSI = si;
  this->SlotIndex = index;
  this->This.Flags = _this->Flags;
  this->This.Bonus.pWeakProxy = _this->Bonus.pWeakProxy;
  this->This.value = _this->value;
  if ( (_this->Flags & 0x1F) > 9 )
  {
    if ( (_this->Flags & 0x200) != 0 )
    {
      ++_this->Bonus.pWeakProxy->RefCount;
      return;
    }
    if ( (_this->Flags & 0x1F) == 10 )
    {
      ++_this->value.VS._1.VStr->RefCount;
    }
    else
    {
      if ( (_this->Flags & 0x1F) <= 0xA )
        return;
      if ( (_this->Flags & 0x1F) <= 0xF )
      {
        VObj = _this->value.VS._1;
      }
      else
      {
        if ( (_this->Flags & 0x1F) > 0x11 )
          return;
        VObj = (Scaleform::GFx::AS3::Value::V1U)_this->value.VS._2.VObj;
      }
      if ( VObj.VStr )
        VObj.VStr->Size = (VObj.VStr->Size + 1) & 0x8FBFFFFF;
    }
  }
}

// File Line: 312
// RVA: 0x790D50
bool __fastcall Scaleform::GFx::AS3::PropRef::operator bool(Scaleform::GFx::AS3::PropRef *this)
{
  return (this->This.Flags & 0x1F) != 0
      && (((__int64)this->pSI & 1) == 0 || ((unsigned __int64)this->pSI & 0xFFFFFFFFFFFFFFFEui64) != 0)
      && (((__int64)this->pSI & 2) == 0 || ((unsigned __int64)this->pSI & 0xFFFFFFFFFFFFFFFDui64) != 0);
}

