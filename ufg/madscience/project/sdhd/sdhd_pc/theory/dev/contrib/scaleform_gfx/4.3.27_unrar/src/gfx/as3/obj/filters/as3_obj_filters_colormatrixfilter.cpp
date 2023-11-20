// File Line: 35
// RVA: 0x1588480
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_filters::ColorMatrixFilter_0_Scaleform::GFx::AS3::SPtr_Scaleform::GFx::AS3::Instances::fl::Array___::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243D9B0 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_filters::ColorMatrixFilter,0,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Array>>::Method = Scaleform::GFx::AS3::Instances::fl_filters::ColorMatrixFilter::matrixGet;
  return result;
}

// File Line: 36
// RVA: 0x158F560
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Instances::fl_filters::ColorMatrixFilter_1_Scaleform::GFx::AS3::Value_const__Scaleform::GFx::AS3::Instances::fl::Array_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243D9C0 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_filters::ColorMatrixFilter,1,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl::Array *>::Method = Scaleform::GFx::AS3::Instances::fl_filters::ColorMatrixFilter::matrixSet;
  return result;
}

// File Line: 37
// RVA: 0x1588450
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_filters::ColorMatrixFilter_2_Scaleform::GFx::AS3::SPtr_Scaleform::GFx::AS3::Instances::fl_filters::BitmapFilter___::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243D9D0 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_filters::ColorMatrixFilter,2,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_filters::BitmapFilter>>::Method = Scaleform::GFx::AS3::Instances::fl_filters::ColorMatrixFilter::clone;
  return result;
}

// File Line: 45
// RVA: 0x77C160
void __fastcall Scaleform::GFx::AS3::Instances::fl_filters::ColorMatrixFilter::ColorMatrixFilter(Scaleform::GFx::AS3::Instances::fl_filters::ColorMatrixFilter *this, Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::Instances::fl_filters::ColorMatrixFilter *v2; // rbx
  Scaleform::Render::Filter *v3; // rdi
  Scaleform::Render::ColorMatrixFilter *v4; // rax
  Scaleform::Render::Filter *v5; // rax
  Scaleform::Render::RenderBuffer *v6; // rcx

  v2 = this;
  Scaleform::GFx::AS3::Instance::Instance((Scaleform::GFx::AS3::Instance *)&this->vfptr, t);
  v2->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::Object::`vftable;
  v2->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_filters::BitmapFilter::`vftable;
  v3 = 0i64;
  v2->FilterData.pObject = 0i64;
  v2->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_filters::ColorMatrixFilter::`vftable;
  v4 = (Scaleform::Render::ColorMatrixFilter *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                                 Scaleform::Memory::pGlobalHeap,
                                                 104ui64,
                                                 0i64);
  if ( v4 )
  {
    Scaleform::Render::ColorMatrixFilter::ColorMatrixFilter(v4);
    v3 = v5;
  }
  v6 = (Scaleform::Render::RenderBuffer *)v2->FilterData.pObject;
  if ( v6 )
    Scaleform::RefCountImpl::Release(v6);
  v2->FilterData.pObject = v3;
}

// File Line: 52
// RVA: 0x853880
void __fastcall Scaleform::GFx::AS3::Instances::fl_filters::ColorMatrixFilter::matrixGet(Scaleform::GFx::AS3::Instances::fl_filters::ColorMatrixFilter *this, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Array> *result)
{
  __int64 *v2; // r15
  Scaleform::GFx::AS3::Instances::fl_filters::ColorMatrixFilter *v3; // rdi
  Scaleform::GFx::AS3::Instances::fl::Array *v4; // rbx
  unsigned __int64 v5; // rax
  unsigned __int64 v6; // r8
  Scaleform::Render::Filter *v7; // r12
  unsigned int v8; // edi
  unsigned __int64 v9; // r14
  Scaleform::GFx::AS3::Value::Extra v10; // xmm8_8
  Scaleform::GFx::AS3::Value::Extra v11; // xmm7_8
  unsigned int v12; // edx
  __int64 v13; // rdx
  float v14; // xmm6_4
  unsigned int v15; // ecx
  Scaleform::GFx::AS3::WeakProxy *v16; // rdx
  bool v17; // zf
  __int64 v18; // rax
  int v19; // ecx
  Scaleform::GFx::AS3::WeakProxy *v20; // rdx
  Scaleform::GFx::ASStringNode *v21; // rcx
  long double v22; // rcx
  int v23; // eax
  int v24; // ecx
  Scaleform::GFx::ASStringNode *v25; // rcx
  long double v26; // rcx
  int v27; // eax
  __int64 v28; // rcx
  int v29; // eax
  unsigned int v30; // eax
  Scaleform::GFx::AS3::Value v; // [rsp+28h] [rbp-58h]
  Scaleform::GFx::AS3::Instances::fl::Array *v32; // [rsp+C0h] [rbp+40h]
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Array> resulta; // [rsp+C8h] [rbp+48h]

  v2 = (__int64 *)result;
  v3 = this;
  Scaleform::GFx::AS3::InstanceTraits::fl::Array::MakeInstance(
    &resulta,
    (Scaleform::GFx::AS3::InstanceTraits::fl::Array *)this->pTraits.pObject->pVM->TraitsArray.pObject->ITraits.pObject);
  v4 = resulta.pV;
  v32 = resulta.pV;
  v5 = resulta.pV->SA.ValueA.Data.Size;
  if ( v5 >= 0x14 && v5 )
  {
    Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
      &resulta.pV->SA.ValueA.Data,
      0x14ui64);
    Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::Clear((Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *)&v4->SA.ValueH.mHash.pTable);
    v4->SA.ValueHLowInd = 0i64;
    v4->SA.ValueHHighInd = 0i64;
  }
  else if ( resulta.pV->SA.ValueHLowInd <= 0x14 )
  {
    v6 = resulta.pV->SA.ValueHHighInd;
    if ( v6 > 0x14 )
      Scaleform::GFx::AS3::Impl::SparseArray::CutHash(&resulta.pV->SA, 0x14ui64, v6 - 19, 0i64);
  }
  else
  {
    Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::Clear((Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *)&resulta.pV->SA.ValueH.mHash.pTable);
    v4->SA.ValueHLowInd = 0i64;
    v4->SA.ValueHHighInd = 0i64;
  }
  v4->SA.Length = 20i64;
  v7 = v3->FilterData.pObject;
  v8 = 0;
  v9 = 0i64;
  v10.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)v.Bonus;
  v11.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)v.Bonus;
  do
  {
    v.Flags = 0;
    v.Bonus.pWeakProxy = 0i64;
    v12 = v8 / 5;
    if ( v8 == 5 * (v8 / 5) && v8 )
    {
      v13 = v12 + 16;
      if ( (unsigned int)v13 >= 0x14 )
        v14 = 0.0;
      else
        v14 = *((float *)&v7[1].vfptr + v13);
      v15 = v.Flags;
      if ( (v.Flags & 0x1F) > 9 )
      {
        if ( (v.Flags >> 9) & 1 )
        {
          v16 = v.Bonus.pWeakProxy;
          v17 = v.Bonus.pWeakProxy->RefCount == 1;
          --v16->RefCount;
          if ( v17 )
            ((void (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::GFx::AS3::WeakProxy *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
              Scaleform::Memory::pGlobalHeap,
              v16,
              5368709120i64);
          v.Bonus.pWeakProxy = 0i64;
          v.value = 0ui64;
          v15 = v.Flags & 0xFFFFFDE0;
          v.Flags &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v);
          v15 = v.Flags;
        }
      }
      v.Flags = v15 & 0xFFFFFFE4 | 4;
      v.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v10.pWeakProxy;
    }
    else
    {
      v18 = v8 - v12;
      if ( (unsigned int)v18 >= 0x14 )
        v14 = 0.0;
      else
        v14 = *((float *)&v7[1].vfptr + v18);
      v19 = v.Flags & 0x1F;
      if ( v19 > 9 )
      {
        if ( (v.Flags >> 9) & 1 )
        {
          v20 = v.Bonus.pWeakProxy;
          v17 = v.Bonus.pWeakProxy->RefCount == 1;
          --v20->RefCount;
          if ( v17 )
            ((void (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::GFx::AS3::WeakProxy *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
              Scaleform::Memory::pGlobalHeap,
              v20,
              5368709120i64);
          v.Bonus.pWeakProxy = 0i64;
          v.value = 0ui64;
          v.Flags &= 0xFFFFFDFF;
          v.Flags &= 0xFFFFFFE0;
        }
        else
        {
          switch ( v19 )
          {
            case 10:
              v21 = v.value.VS._1.VStr;
              v17 = *(_DWORD *)(*(_QWORD *)&v.value.VNumber + 24i64) == 1;
              --v21->RefCount;
              if ( v17 )
                Scaleform::GFx::ASStringNode::ReleaseNode(v21);
              break;
            case 11:
            case 12:
            case 13:
            case 14:
            case 15:
              v22 = v.value.VNumber;
              if ( !v.value.VS._1.VBool )
                goto LABEL_36;
              --*(_QWORD *)&v.value.VNumber;
              break;
            case 16:
            case 17:
              v22 = *(double *)&v.value.VS._2.VObj;
              if ( (_QWORD)v.value.VS._2.VObj & 1 )
              {
                --v.value.VS._2.VObj;
              }
              else
              {
LABEL_36:
                if ( v22 != 0.0 )
                {
                  v23 = *(_DWORD *)(*(_QWORD *)&v22 + 32i64);
                  if ( v23 & 0x3FFFFF )
                  {
                    *(_DWORD *)(*(_QWORD *)&v22 + 32i64) = v23 - 1;
                    Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(*(Scaleform::GFx::AS3::RefCountBaseGC<328> **)&v22);
                  }
                }
              }
              break;
            default:
              break;
          }
        }
      }
      v.Flags = v.Flags & 0xFFFFFFE4 | 4;
      v.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v11.pWeakProxy;
    }
    v.value.VNumber = v14;
    Scaleform::GFx::AS3::Impl::SparseArray::Set(&v4->SA, v9, &v);
    v24 = v.Flags & 0x1F;
    if ( v24 > 9 )
    {
      if ( (v.Flags >> 9) & 1 )
      {
        v17 = v.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v17 )
          ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        v.Bonus.pWeakProxy = 0i64;
        v.value = 0ui64;
        v.Flags &= 0xFFFFFDE0;
      }
      else
      {
        switch ( v24 )
        {
          case 10:
            v25 = v.value.VS._1.VStr;
            v17 = *(_DWORD *)(*(_QWORD *)&v.value.VNumber + 24i64) == 1;
            --v25->RefCount;
            if ( v17 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v25);
            break;
          case 11:
          case 12:
          case 13:
          case 14:
          case 15:
            v26 = v.value.VNumber;
            if ( !v.value.VS._1.VBool )
              goto LABEL_52;
            --*(_QWORD *)&v.value.VNumber;
            break;
          case 16:
          case 17:
            v26 = *(double *)&v.value.VS._2.VObj;
            if ( (_QWORD)v.value.VS._2.VObj & 1 )
            {
              --v.value.VS._2.VObj;
            }
            else
            {
LABEL_52:
              if ( v26 != 0.0 )
              {
                v27 = *(_DWORD *)(*(_QWORD *)&v26 + 32i64);
                if ( v27 & 0x3FFFFF )
                {
                  *(_DWORD *)(*(_QWORD *)&v26 + 32i64) = v27 - 1;
                  Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(*(Scaleform::GFx::AS3::RefCountBaseGC<328> **)&v26);
                }
              }
            }
            break;
          default:
            break;
        }
      }
    }
    ++v8;
    ++v9;
  }
  while ( v8 < 0x14 );
  if ( &v32 != (Scaleform::GFx::AS3::Instances::fl::Array **)v2 )
  {
    if ( v4 )
      v4->RefCount = (v4->RefCount + 1) & 0x8FBFFFFF;
    v28 = *v2;
    if ( *v2 )
    {
      if ( v28 & 1 )
      {
        *v2 = v28 - 1;
      }
      else
      {
        v29 = *(_DWORD *)(v28 + 32);
        if ( v29 & 0x3FFFFF )
        {
          *(_DWORD *)(v28 + 32) = v29 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)v28);
        }
      }
    }
    *v2 = (__int64)v4;
  }
  if ( v4 )
  {
    if ( (unsigned __int8)v4 & 1 )
    {
      v32 = (Scaleform::GFx::AS3::Instances::fl::Array *)((char *)v4 - 1);
    }
    else
    {
      v30 = v4->RefCount;
      if ( v30 & 0x3FFFFF )
      {
        v4->RefCount = v30 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v4->vfptr);
      }
    }
  }
}Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v4->vfptr);
      }
    }
  }
}

// File Line: 73
// RVA: 0x853EC0
void __fastcall Scaleform::GFx::AS3::Instances::fl_filters::ColorMatrixFilter::matrixSet(Scaleform::GFx::AS3::Instances::fl_filters::ColorMatrixFilter *this, Scaleform::GFx::AS3::Value *result, Scaleform::GFx::AS3::Instances::fl::Array *value)
{
  Scaleform::Render::Filter *v3; // rbp
  unsigned int v4; // edi
  Scaleform::GFx::AS3::Instances::fl::Array *v5; // rbx
  unsigned __int64 v6; // rax
  Scaleform::GFx::AS3::Value *v7; // rax
  signed __int64 v8; // rax
  signed __int64 v9; // rax
  float v10; // xmm0_4
  unsigned int v11; // edx
  __int64 v12; // rax
  unsigned __int64 key; // [rsp+20h] [rbp-38h]
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+70h] [rbp+18h]
  long double v15; // [rsp+78h] [rbp+20h]

  if ( value )
  {
    v3 = this->FilterData.pObject;
    v4 = 0;
    v5 = value;
    if ( value->SA.Length )
    {
      v6 = 0i64;
      do
      {
        key = v6;
        if ( v6 >= v5->SA.ValueA.Data.Size )
        {
          if ( v6 < v5->SA.ValueHLowInd
            || v6 > v5->SA.ValueHHighInd
            || (v8 = Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::findIndexAlt<unsigned __int64>(
                       (Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *)&v5->SA.ValueH.mHash.pTable,
                       &key),
                v8 < 0)
            || (v9 = (signed __int64)&v5->SA.ValueH.mHash.pTable[2] + 56 * v8) == 0
            || (v7 = (Scaleform::GFx::AS3::Value *)(v9 + 8)) == 0i64 )
          {
            v7 = &v5->SA.DefaultValue;
          }
        }
        else
        {
          v7 = &v5->SA.ValueA.Data.Data[v6];
        }
        if ( !Scaleform::GFx::AS3::Value::Convert2Number(v7, &resulta, &v15)->Result )
          break;
        if ( v4 < 0x14 )
        {
          v10 = v15;
          v11 = v4 / 5;
          if ( v4 % 5 == 4 )
          {
            v10 = v10 * 0.0039215689;
            v12 = v11 + 16;
          }
          else
          {
            v12 = v4 - v11;
          }
          *((float *)&v3[1].vfptr + v12) = v10;
        }
        v6 = ++v4;
      }
      while ( v4 < v5->SA.Length );
    }
  }
}

// File Line: 98
// RVA: 0x82F490
void __fastcall Scaleform::GFx::AS3::Instances::fl_filters::ColorMatrixFilter::clone(Scaleform::GFx::AS3::Instances::fl_filters::ColorMatrixFilter *this, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_filters::BitmapFilter> *result)
{
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_filters::BitmapFilter> *v2; // rsi
  Scaleform::GFx::AS3::Instances::fl_filters::ColorMatrixFilter *v3; // rbx
  Scaleform::GFx::AS3::Instances::fl::Array *v4; // rbx
  Scaleform::GFx::AS3::Instances::fl_filters::ColorMatrixFilter *v5; // rdi
  Scaleform::GFx::AS3::Instances::fl_filters::BitmapFilter *v6; // rcx
  unsigned int v7; // eax
  unsigned int v8; // eax
  Scaleform::GFx::AS3::Value v9; // [rsp+28h] [rbp-30h]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Array> v10; // [rsp+60h] [rbp+8h]
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_filters::ColorMatrixFilter> resulta; // [rsp+68h] [rbp+10h]

  v2 = result;
  v3 = this;
  Scaleform::GFx::AS3::InstanceTraits::fl_filters::ColorMatrixFilter::MakeInstance(
    &resulta,
    (Scaleform::GFx::AS3::InstanceTraits::fl_filters::ColorMatrixFilter *)this->pTraits.pObject);
  v10.pObject = 0i64;
  v9.Flags = 0;
  v9.Bonus.pWeakProxy = 0i64;
  Scaleform::GFx::AS3::Instances::fl_filters::ColorMatrixFilter::matrixGet(v3, &v10);
  v4 = v10.pObject;
  v5 = resulta.pV;
  Scaleform::GFx::AS3::Instances::fl_filters::ColorMatrixFilter::matrixSet(resulta.pV, &v9, v10.pObject);
  v6 = v2->pObject;
  if ( v5 != (Scaleform::GFx::AS3::Instances::fl_filters::ColorMatrixFilter *)v2->pObject )
  {
    if ( v6 )
    {
      if ( (unsigned __int8)v6 & 1 )
      {
        v2->pObject = (Scaleform::GFx::AS3::Instances::fl_filters::BitmapFilter *)((char *)v6 - 1);
      }
      else
      {
        v7 = v6->RefCount;
        if ( v7 & 0x3FFFFF )
        {
          v6->RefCount = v7 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v6->vfptr);
        }
      }
    }
    v2->pObject = (Scaleform::GFx::AS3::Instances::fl_filters::BitmapFilter *)&v5->vfptr;
  }
  if ( v4 )
  {
    if ( (unsigned __int8)v4 & 1 )
    {
      v10.pObject = (Scaleform::GFx::AS3::Instances::fl::Array *)((char *)v4 - 1);
    }
    else
    {
      v8 = v4->RefCount;
      if ( v8 & 0x3FFFFF )
      {
        v4->RefCount = v8 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v4->vfptr);
      }
    }
  }
}

// File Line: 128
// RVA: 0x795770
void __fastcall Scaleform::GFx::AS3::Instances::fl_filters::ColorMatrixFilter::AS3Constructor(Scaleform::GFx::AS3::Instances::fl_filters::ColorMatrixFilter *this, unsigned int argc, Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Instances::fl_filters::ColorMatrixFilter *v3; // rbx
  Scaleform::GFx::AS3::VM::Error *v4; // rax
  Scaleform::GFx::ASStringNode *v5; // rcx
  bool v6; // zf
  long double v7; // rax
  __int64 v8; // rcx
  Scaleform::GFx::AS3::VM::Error v9; // [rsp+28h] [rbp-30h]

  v3 = this;
  if ( argc < 2 )
  {
    if ( argc )
    {
      if ( (argv->Flags & 0x1F) - 12 <= 3 )
      {
        v7 = argv->value.VNumber;
        if ( v7 != 0.0 )
        {
          v8 = *(_QWORD *)(*(_QWORD *)&v7 + 40i64);
          if ( *(_DWORD *)(v8 + 120) == 7 )
          {
            if ( ~(*(_BYTE *)(v8 + 112) >> 5) & 1 )
            {
              v9.ID = 0;
              v9.Message.pNode = 0i64;
              Scaleform::GFx::AS3::Instances::fl_filters::ColorMatrixFilter::matrixSet(
                v3,
                (Scaleform::GFx::AS3::Value *)&v9,
                (Scaleform::GFx::AS3::Instances::fl::Array *)argv->value.VS._1.VStr);
            }
          }
        }
      }
    }
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v9, eWrongArgumentCountError, this->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v3->pTraits.pObject->pVM, v4, &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
    v5 = v9.Message.pNode;
    v6 = v9.Message.pNode->RefCount == 1;
    --v5->RefCount;
    if ( v6 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v5);
  }
}

// File Line: 182
// RVA: 0x7FF310
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl_filters::ColorMatrixFilter::MakeObject(Scaleform::GFx::AS3::InstanceTraits::fl_filters::ColorMatrixFilter *this, Scaleform::GFx::AS3::Value *result, Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::Value *v3; // rbx
  Scaleform::GFx::AS3::Object **v4; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_filters::ColorMatrixFilter> resulta; // [rsp+48h] [rbp+20h]

  v3 = result;
  v4 = (Scaleform::GFx::AS3::Object **)Scaleform::GFx::AS3::InstanceTraits::fl_filters::ColorMatrixFilter::MakeInstance(
                                         &resulta,
                                         (Scaleform::GFx::AS3::InstanceTraits::fl_filters::ColorMatrixFilter *)t);
  Scaleform::GFx::AS3::Value::Pick(v3, *v4);
}

// File Line: 204
// RVA: 0x73B1E0
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl_filters::ColorMatrixFilter::MakeClassTraits(Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result, Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::GFx::AS3::VM *v2; // rbp
  Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *v3; // rdi
  Scaleform::MemoryHeap *v4; // rsi
  Scaleform::GFx::AS3::ClassTraits::Traits *v5; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v6; // rbx
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v7; // rax
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v8; // rbx
  Scaleform::GFx::AS3::Class *v9; // rax

  v2 = vm;
  v3 = result;
  v4 = vm->MHeap;
  v5 = (Scaleform::GFx::AS3::ClassTraits::Traits *)v4->vfptr->Alloc(v4, 208ui64, 0i64);
  v6 = v5;
  if ( v5 )
  {
    Scaleform::GFx::AS3::ClassTraits::Traits::Traits(v5, v2, &Scaleform::GFx::AS3::fl_filters::ColorMatrixFilterCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl::Object::`vftable;
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_filters::BitmapFilter::`vftable;
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_filters::ColorMatrixFilter::`vftable;
  }
  else
  {
    v6 = 0i64;
  }
  v3->pV = v6;
  v7 = (Scaleform::GFx::AS3::InstanceTraits::CTraits *)v4->vfptr->Alloc(v4, 240ui64, 0i64);
  v8 = v7;
  if ( v7 )
  {
    Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(v7, v2, &Scaleform::GFx::AS3::fl_filters::ColorMatrixFilterCI);
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::Object::`vftable;
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_filters::BitmapFilter::`vftable;
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_filters::ColorMatrixFilter::`vftable;
  }
  else
  {
    v8 = 0i64;
  }
  Scaleform::GFx::AS3::ClassTraits::Traits::SetInstanceTraits(
    v3->pV,
    (Scaleform::Pickable<Scaleform::GFx::AS3::InstanceTraits::Traits>)v8);
  v9 = (Scaleform::GFx::AS3::Class *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))v4->vfptr->Alloc)(
                                       v4,
                                       72i64);
  if ( v9 )
    Scaleform::GFx::AS3::Class::Class(v9, v3->pV);
  return v3;
}

