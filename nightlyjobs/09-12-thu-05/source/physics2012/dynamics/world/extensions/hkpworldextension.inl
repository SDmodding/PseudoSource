// File Line: 35
// RVA: 0xD5E380
void __fastcall hkpWorldExtension::requireExtension<hkpCollisionCallbackUtil>(hkpWorldExtension *this, hkpWorld *world)
{
  hkpWorld *v2; // rdi
  hkpWorldExtension *v3; // rax
  _QWORD **v4; // rax
  hkpWorldExtension *v5; // rax
  hkpWorldExtension *v6; // rbx

  v2 = (hkpWorld *)this;
  v3 = hkpWorld::findWorldExtension((hkpWorld *)this, 1001);
  if ( v3 )
  {
    ++v3->m_attachmentCount;
  }
  else
  {
    v4 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v5 = (hkpWorldExtension *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v4[11] + 8i64))(v4[11], 120i64);
    v6 = v5;
    if ( v5 )
    {
      hkpWorldExtension::hkpWorldExtension(v5, 1001);
      v6->vfptr = (hkBaseObjectVtbl *)&hkpCollisionCallbackUtil::`vftable'{for `hkpWorldExtension'};
      v6[1].vfptr = (hkBaseObjectVtbl *)&hkpCollisionCallbackUtil::`vftable'{for `hkpConstraintListener'};
      hkpEndOfStepCallbackUtil::hkpEndOfStepCallbackUtil((hkpEndOfStepCallbackUtil *)&v6[1].m_memSizeAndFlags);
    }
    else
    {
      v6 = 0i64;
    }
    hkpWorld::addWorldExtension(v2, v6);
    hkReferencedObject::removeReference((hkReferencedObject *)&v6->vfptr);
    ++v6->m_attachmentCount;
  }
}

// File Line: 48
// RVA: 0xE1BB60
void __fastcall hkpWorldExtension::releaseExtension<hkpCollisionCallbackUtil>(hkpWorldExtension *this, hkpWorld *world)
{
  hkpWorld *v2; // rbx
  hkpWorldExtension *v3; // rax
  bool v4; // zf

  v2 = (hkpWorld *)this;
  v3 = hkpWorld::findWorldExtension((hkpWorld *)this, 1001);
  v4 = v3->m_attachmentCount-- == 1;
  if ( v4 )
    hkpWorld::removeWorldExtension(v2, v3);
}

