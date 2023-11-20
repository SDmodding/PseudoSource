// File Line: 377
// RVA: 0x719A60
__int64 __fastcall Scaleform::GFx::AS2::AvmCharacter::SetMemberRaw(Scaleform::GFx::AS2::AvmCharacter *this, Scaleform::GFx::AS2::ASStringContext *psc, Scaleform::GFx::ASString *name, Scaleform::GFx::AS2::Value *val, Scaleform::GFx::AS2::PropFlags *flags)
{
  Scaleform::GFx::AvmDisplayObjBaseVtbl *v5; // rbx
  Scaleform::GFx::AS2::AvmCharacter *v6; // rdi
  Scaleform::GFx::AS2::Value *v7; // rsi
  Scaleform::GFx::ASString *v8; // rbp
  __int64 v9; // rax

  v5 = this->vfptr;
  v6 = this;
  v7 = val;
  v8 = name;
  v9 = ((__int64 (__fastcall *)(Scaleform::HashLH<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor,323,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *, Scaleform::GFx::AS2::ASStringContext *))this[-1].EventHandlers.mHash.pTable[15].EntryCount)(
         &this[-1].EventHandlers,
         psc);
  return ((__int64 (__fastcall *)(Scaleform::GFx::AS2::AvmCharacter *, __int64, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))v5->ToAvmButttonBase)(
           v6,
           v9,
           v8,
           v7);
}

// File Line: 382
// RVA: 0x6F3870
__int64 __fastcall Scaleform::GFx::AS2::AvmCharacter::GetMemberRaw(Scaleform::GFx::AS2::AvmCharacter *this, Scaleform::GFx::AS2::ASStringContext *psc, Scaleform::GFx::ASString *name, Scaleform::GFx::AS2::Value *val)
{
  Scaleform::GFx::AvmDisplayObjBaseVtbl *v4; // rbx
  Scaleform::GFx::AS2::AvmCharacter *v5; // rdi
  Scaleform::GFx::AS2::Value *v6; // rsi
  Scaleform::GFx::ASString *v7; // rbp
  __int64 v8; // rax

  v4 = this->vfptr;
  v5 = this;
  v6 = val;
  v7 = name;
  v8 = ((__int64 (__fastcall *)(Scaleform::HashLH<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor,323,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *, Scaleform::GFx::AS2::ASStringContext *))this[-1].EventHandlers.mHash.pTable[15].EntryCount)(
         &this[-1].EventHandlers,
         psc);
  return ((__int64 (__fastcall *)(Scaleform::GFx::AS2::AvmCharacter *, __int64, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))v4->ToAvmTextFieldBase)(
           v5,
           v8,
           v7,
           v6);
}

// File Line: 456
// RVA: 0x6EE700
Scaleform::Render::Rect<float> *__fastcall Scaleform::GFx::AS2::GenericDisplayObj::GetBounds(Scaleform::GFx::AS2::GenericDisplayObj *this, Scaleform::Render::Rect<float> *result, Scaleform::Render::Matrix2x4<float> *transform)
{
  Scaleform::GFx::ShapeBaseCharacterDef *v3; // rbx
  Scaleform::Render::Matrix2x4<float> *v4; // rsi
  Scaleform::GFx::ResourceVtbl *v5; // rdi
  Scaleform::Render::Rect<float> *v6; // rbp
  Scaleform::Render::Rect<float> *v7; // rax
  char v9; // [rsp+20h] [rbp-18h]

  v3 = this->pDef.pObject;
  v4 = transform;
  v5 = v3->vfptr;
  v6 = result;
  ((void (*)(void))this->vfptr[17].__vecDelDtor)();
  v7 = (Scaleform::Render::Rect<float> *)((__int64 (__fastcall *)(Scaleform::GFx::ShapeBaseCharacterDef *, char *))v5[1].GetResourceReport)(
                                           v3,
                                           &v9);
  Scaleform::Render::Matrix2x4<float>::EncloseTransform(v4, v6, v7);
  return v6;
}

// File Line: 460
// RVA: 0x6F5150
Scaleform::Render::Rect<float> *__fastcall Scaleform::GFx::AS2::GenericDisplayObj::GetRectBounds(Scaleform::GFx::AS2::GenericDisplayObj *this, Scaleform::Render::Rect<float> *result, Scaleform::Render::Matrix2x4<float> *transform)
{
  Scaleform::GFx::ShapeBaseCharacterDef *v3; // rbx
  Scaleform::Render::Matrix2x4<float> *v4; // rsi
  Scaleform::GFx::ResourceVtbl *v5; // rdi
  Scaleform::Render::Rect<float> *v6; // rbp
  Scaleform::Render::Rect<float> *v7; // rax
  char v9; // [rsp+20h] [rbp-18h]

  v3 = this->pDef.pObject;
  v4 = transform;
  v5 = v3->vfptr;
  v6 = result;
  ((void (*)(void))this->vfptr[17].__vecDelDtor)();
  v7 = (Scaleform::Render::Rect<float> *)v5[2].__vecDelDtor((Scaleform::GFx::Resource *)&v3->vfptr, (unsigned int)&v9);
  Scaleform::Render::Matrix2x4<float>::EncloseTransform(v4, v6, v7);
  return v6;
}

