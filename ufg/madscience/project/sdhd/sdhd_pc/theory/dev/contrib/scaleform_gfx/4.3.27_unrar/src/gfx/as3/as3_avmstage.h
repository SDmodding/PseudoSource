// File Line: 91
// RVA: 0x7F0B20
Scaleform::GFx::AS3::Stage *__fastcall Scaleform::GFx::AS3::Stage::GetTopParent(Scaleform::GFx::AS3::Stage *this, __int64 ignoreLockRoot)
{
  Scaleform::GFx::InteractiveObject *v2; // r8
  Scaleform::GFx::AS3::Stage *result; // rax

  v2 = this->pParent;
  if ( v2 )
    result = (Scaleform::GFx::AS3::Stage *)v2->vfptr[68].__vecDelDtor(
                                             (Scaleform::RefCountNTSImplCore *)&this->pParent->vfptr,
                                             ignoreLockRoot);
  else
    result = this;
  return result;
}

// File Line: 117
// RVA: 0x77B190
void __fastcall Scaleform::GFx::AS3::AvmStage::AvmStage(Scaleform::GFx::AS3::AvmStage *this, Scaleform::GFx::DisplayObjContainer *pobj)
{
  Scaleform::GFx::AS3::AvmStage *v2; // rbx
  Scaleform::GFx::AvmDisplayObjContainerBase *v3; // [rsp+50h] [rbp+18h]

  v2 = this;
  Scaleform::GFx::AS3::AvmInteractiveObj::AvmInteractiveObj(
    (Scaleform::GFx::AS3::AvmInteractiveObj *)&this->vfptr,
    (Scaleform::GFx::InteractiveObject *)&pobj->vfptr);
  v3 = (Scaleform::GFx::AvmDisplayObjContainerBase *)&v2->vfptr;
  v3->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AvmDisplayObjBase::`vftable';
  v3->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AvmInteractiveObjBase::`vftable';
  v3->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AvmDisplayObjContainerBase::`vftable';
  v2->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AS3::AvmDisplayObjContainer::`vftable'{for `Scaleform::GFx::AS3::AvmDisplayObj'};
  v2->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AS3::AvmDisplayObjContainer::`vftable'{for `Scaleform::GFx::AvmInteractiveObjBase'};
  v3->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AS3::AvmDisplayObjContainer::`vftable';
  v2->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AS3::AvmStage::`vftable'{for `Scaleform::GFx::AS3::AvmDisplayObj'};
  v2->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AS3::AvmStage::`vftable'{for `Scaleform::GFx::AvmInteractiveObjBase'};
  v3->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AS3::AvmStage::`vftable';
}

// File Line: 128
// RVA: 0x7E77E0
const char *__fastcall Scaleform::GFx::AS3::AvmStage::GetDefaultASClassName(Scaleform::GFx::AS3::AvmStage *this)
{
  return "flash.display.Stage";
}

