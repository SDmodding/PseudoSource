// File Line: 112
// RVA: 0x6D15E0
void __fastcall Scaleform::GFx::AS2::FunctionRef::~FunctionRef(Scaleform::GFx::AS2::FunctionRef *this)
{
  Scaleform::GFx::AS2::FunctionRef *v1; // rbx
  Scaleform::GFx::AS2::FunctionObject *v2; // rcx
  unsigned int v3; // eax
  bool v4; // zf
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v5; // rcx
  unsigned int v6; // eax

  v1 = this;
  if ( !(this->Flags & 2) )
  {
    v2 = this->Function;
    if ( v2 )
    {
      v3 = v2->RefCount;
      if ( v3 & 0x3FFFFFF )
      {
        v2->RefCount = v3 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v2->vfptr);
      }
    }
  }
  v4 = (v1->Flags & 1) == 0;
  v1->Function = 0i64;
  if ( v4 )
  {
    v5 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v1->pLocalFrame->vfptr;
    if ( v5 )
    {
      v6 = v5->RefCount;
      if ( v6 & 0x3FFFFFF )
      {
        v5->RefCount = v6 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v5);
      }
    }
  }
  v1->pLocalFrame = 0i64;
}

