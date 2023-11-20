// File Line: 100
// RVA: 0x7F8B40
char __fastcall Scaleform::GFx::AS3::InstanceTraits::Traits::IsOfType(Scaleform::GFx::AS3::InstanceTraits::Traits *this, Scaleform::GFx::AS3::InstanceTraits::Traits *other)
{
  Scaleform::GFx::AS3::InstanceTraits::Traits *v2; // rdi
  Scaleform::GFx::AS3::InstanceTraits::Traits *v3; // rbx

  v2 = other;
  v3 = this;
  if ( other == this )
    return 1;
  if ( this )
  {
    while ( !((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS3::InstanceTraits::Traits *, Scaleform::GFx::AS3::InstanceTraits::Traits *))v3->vfptr[4].~RefCountBaseGC<328>)(
               v3,
               v2) )
    {
      v3 = (Scaleform::GFx::AS3::InstanceTraits::Traits *)v3->pParent.pObject;
      if ( v3 == v2 )
        break;
      if ( !v3 )
        return 0;
    }
    return 1;
  }
  return 0;
}

// File Line: 264
// RVA: 0x7FACE0
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Array> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl::Array::MakeInstance(Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Array> *result, Scaleform::GFx::AS3::InstanceTraits::fl::Array *t)
{
  Scaleform::GFx::AS3::InstanceTraits::fl::Array *v2; // rdi
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Array> *v3; // rbx
  Scaleform::GFx::AS3::Instances::fl::Array *v4; // rax
  int v6; // [rsp+40h] [rbp+8h]
  Scaleform::GFx::AS3::Instances::fl::Array *v7; // [rsp+48h] [rbp+10h]
  Scaleform::GFx::AS3::Instances::fl::Array *v8; // [rsp+50h] [rbp+18h]

  v2 = t;
  v3 = result;
  v6 = 337;
  v4 = (Scaleform::GFx::AS3::Instances::fl::Array *)t->pVM->MHeap->vfptr->Alloc(
                                                      t->pVM->MHeap,
                                                      t->MemSize,
                                                      (Scaleform::AllocInfo *)&v6);
  v7 = v4;
  v8 = v4;
  if ( v4 )
    Scaleform::GFx::AS3::Instances::fl::Array::Array(v4, (Scaleform::GFx::AS3::InstanceTraits::Traits *)&v2->vfptr);
  v3->pV = v4;
  return v3;
}

