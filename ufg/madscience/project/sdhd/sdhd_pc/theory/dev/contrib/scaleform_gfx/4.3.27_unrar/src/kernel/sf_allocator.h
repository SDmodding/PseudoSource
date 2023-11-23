// File Line: 322
// RVA: 0x962640
void __fastcall Scaleform::ConstructorMov<Scaleform::Render::Matrix4x4<float>>::Construct(
        Scaleform::Render::Matrix4x4<float> *p,
        Scaleform::Render::Matrix4x4<float> *source)
{
  if ( p )
    *p = *source;
}

// File Line: 334
// RVA: 0x8BDAB0
void __fastcall Scaleform::ConstructorMov<Scaleform::Render::TextureGlyph>::ConstructArray(
        _DWORD *p,
        unsigned __int64 count)
{
  for ( ; count; --count )
  {
    if ( p )
    {
      *(_QWORD *)p = &Scaleform::RefCountImplCore::`vftable;
      p[2] = 1;
      *(_QWORD *)p = &Scaleform::RefCountImpl::`vftable;
      *(_QWORD *)p = &Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
      *(_QWORD *)p = &Scaleform::RefCountBase<Scaleform::Render::TextureGlyph,2>::`vftable;
      *(_QWORD *)p = &Scaleform::Render::TextureGlyph::`vftable;
      *((_QWORD *)p + 2) = 0i64;
      *((_QWORD *)p + 4) = 0i64;
      *((_QWORD *)p + 5) = 0i64;
      p[14] = -1;
    }
    p += 16;
  }
}

// File Line: 348
// RVA: 0x7B96C0
void __fastcall Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::ConstructArray(
        _QWORD *p,
        unsigned __int64 count,
        Scaleform::GFx::AS3::Value *psource)
{
  unsigned __int64 v3; // r10
  Scaleform::GFx::AS3::Value::VU *p_value; // rax
  int VInt; // edx
  Scaleform::GFx::AS3::Value::V2U v7; // rdx

  if ( count )
  {
    v3 = count;
    p_value = &psource->value;
    do
    {
      if ( p )
      {
        *(_DWORD *)p = p_value[-1].VS._1.VInt;
        p[1] = p_value[-1].VS._2.VObj;
        p[2] = p_value->VS._1.VStr;
        p[3] = p_value->VS._2.VObj;
        VInt = p_value[-1].VS._1.VInt;
        if ( (VInt & 0x1Fu) > 9 )
        {
          if ( (VInt & 0x200) != 0 )
          {
            ++LODWORD(p_value[-1].VS._2.VObj->vfptr);
          }
          else if ( (p_value[-1].VS._1.VInt & 0x1F) == 10 )
          {
            ++p_value->VS._1.VStr->RefCount;
          }
          else if ( (p_value[-1].VS._1.VInt & 0x1Fu) > 0xA )
          {
            if ( (p_value[-1].VS._1.VInt & 0x1Fu) <= 0xF )
            {
              if ( p_value->VS._1.VStr )
                p_value->VS._1.VStr->Size = (p_value->VS._1.VStr->Size + 1) & 0x8FBFFFFF;
            }
            else if ( (p_value[-1].VS._1.VInt & 0x1Fu) <= 0x11 )
            {
              v7.VObj = (Scaleform::GFx::AS3::Object *)p_value->VS._2;
              if ( v7.VObj )
                v7.VObj->RefCount = (v7.VObj->RefCount + 1) & 0x8FBFFFFF;
            }
          }
        }
      }
      p_value += 2;
      p += 4;
      --v3;
    }
    while ( v3 );
  }
}

// File Line: 361
// RVA: 0x6E22D0
void __fastcall Scaleform::ConstructorMov<Scaleform::Render::Text::DocView::ImageSubstitutor::Element>::DestructArray(
        Scaleform::Render::Text::DocView::ImageSubstitutor::Element *p,
        unsigned __int64 count)
{
  unsigned __int64 v2; // rdi
  Scaleform::Render::Text::DocView::ImageSubstitutor::Element *v3; // rbx
  Scaleform::RefCountNTSImpl *pObject; // rcx

  if ( count )
  {
    v2 = count;
    v3 = &p[count - 1];
    do
    {
      pObject = v3->pImageDesc.pObject;
      if ( pObject )
        Scaleform::RefCountNTSImpl::Release(pObject);
      --v3;
      --v2;
    }
    while ( v2 );
  }
}

// File Line: 395
// RVA: 0x6DEFA0
void __fastcall Scaleform::ConstructorCPP<Scaleform::GFx::Value>::Construct(_QWORD *p, Scaleform::GFx::Value *source)
{
  Scaleform::GFx::Value::ObjectInterface *pObjectInterface; // rcx

  if ( p )
  {
    p[2] = 0i64;
    *((_DWORD *)p + 6) = source->Type;
    p[4] = source->mValue.pString;
    p[5] = source->DataAux;
    if ( (source->Type & 0x40) != 0 )
    {
      pObjectInterface = source->pObjectInterface;
      p[2] = pObjectInterface;
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, _QWORD *, _QWORD))pObjectInterface->vfptr->gap8)(
        pObjectInterface,
        p,
        p[4]);
    }
  }
}

// File Line: 434
// RVA: 0x7C42E0
void __fastcall Scaleform::ConstructorCPP<Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript::Descr>::DestructArray(
        Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript::Descr *p,
        unsigned __int64 count)
{
  unsigned __int64 v2; // rdi
  Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript::Descr *v3; // rbx
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // rdx

  if ( count )
  {
    v2 = count;
    v3 = &p[count - 1];
    do
    {
      if ( (v3->Method.Flags & 0x1F) > 9 )
      {
        if ( (v3->Method.Flags & 0x200) != 0 )
        {
          pWeakProxy = v3->Method.Bonus.pWeakProxy;
          if ( pWeakProxy->RefCount-- == 1 )
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          v3->Method.Bonus.pWeakProxy = 0i64;
          v3->Method.value.VS._1.VStr = 0i64;
          v3->Method.value.VS._2.VObj = 0i64;
          v3->Method.Flags &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v3->Method);
        }
      }
      --v3;
      --v2;
    }
    while ( v2 );
  }
}

