// File Line: 179
// RVA: 0x8D6200
Scaleform::GFx::TimelineDef *__fastcall Scaleform::GFx::Sprite::GetCharacterDef(Scaleform::GFx::Sprite *this)
{
  return this->pDef.pObject;
}

// File Line: 203
// RVA: 0x8E2F10
__int64 __fastcall Scaleform::GFx::Sprite::HasLooped(Scaleform::GFx::Sprite *this)
{
  return ((unsigned int)(unsigned __int8)this->Flags >> 1) & 1;
}

// File Line: 274
// RVA: 0x8D6650
__int64 __fastcall Scaleform::GFx::Sprite::GetCurrentFrame(Scaleform::GFx::Sprite *this)
{
  return this->CurrentFrame;
}

// File Line: 278
// RVA: 0x8D9B60
Scaleform::GFx::Sprite *__fastcall Scaleform::GFx::Sprite::GetHitAreaHolder(Scaleform::GFx::Sprite *this)
{
  return this->pHitAreaHolder;
}

// File Line: 288
// RVA: 0x8DAA80
__int64 __fastcall Scaleform::GFx::Sprite::GetLabeledFrame(Scaleform::GFx::Sprite *this, const char *label, unsigned int *frameNumber, __int64 translateNumbers)
{
  return ((__int64 (__fastcall *)(Scaleform::GFx::TimelineDef *, const char *, unsigned int *, __int64))this->pDef.pObject->vfptr[3].GetKey)(
           this->pDef.pObject,
           label,
           frameNumber,
           translateNumbers);
}

// File Line: 294
// RVA: 0x8DC130
signed __int64 __fastcall Scaleform::GFx::Sprite::GetPlayState(Scaleform::GFx::Sprite *this)
{
  signed __int64 result; // rax

  if ( (this->Flags >> 11) & 1 )
    result = (unsigned int)this->PlayStatePriv;
  else
    result = 1i64;
  return result;
}

