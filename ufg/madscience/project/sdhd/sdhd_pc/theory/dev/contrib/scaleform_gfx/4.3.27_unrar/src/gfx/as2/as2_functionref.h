// File Line: 112
// RVA: 0x6D15E0
void __fastcall Scaleform::GFx::AS2::FunctionRef::~FunctionRef(Scaleform::GFx::AS2::FunctionRef *this)
{
  Scaleform::GFx::AS2::FunctionObject *Function; // rcx
  unsigned int RefCount; // eax
  bool v4; // zf
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // rcx
  unsigned int v6; // eax

  if ( (this->Flags & 2) == 0 )
  {
    Function = this->Function;
    if ( Function )
    {
      RefCount = Function->RefCount;
      if ( (RefCount & 0x3FFFFFF) != 0 )
      {
        Function->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(Function);
      }
    }
  }
  v4 = (this->Flags & 1) == 0;
  this->Function = 0i64;
  if ( v4 )
  {
    pLocalFrame = this->pLocalFrame;
    if ( pLocalFrame )
    {
      v6 = pLocalFrame->RefCount;
      if ( (v6 & 0x3FFFFFF) != 0 )
      {
        pLocalFrame->RefCount = v6 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
      }
    }
  }
  this->pLocalFrame = 0i64;
}

