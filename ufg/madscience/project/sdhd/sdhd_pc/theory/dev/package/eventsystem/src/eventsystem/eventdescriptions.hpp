// File Line: 55
// RVA: 0x4CBA90
void __fastcall UFG::TeleportEvent::TeleportEvent(UFG::TeleportEvent *this, unsigned int uidSimObject, unsigned int uidXForm, const char *pName)
{
  unsigned int v4; // er10
  UFG::qNode<UFG::Event,UFG::Event> *v5; // rax
  float v6; // xmm1_4
  float v7; // xmm2_4
  float v8; // xmm3_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm3_4
  float v12; // xmm1_4
  float v13; // xmm2_4
  float v14; // xmm3_4
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v17; // xmm3_4

  v4 = UFG::TeleportEvent::EVENT_UID;
  v5 = (UFG::qNode<UFG::Event,UFG::Event> *)&this->mPrev;
  v5->mPrev = v5;
  v5->mNext = v5;
  this->vfptr = (UFG::EventVtbl *)&UFG::Event::`vftable;
  this->m_EventUID = v4;
  this->m_NamePTR = pName;
  this->vfptr = (UFG::EventVtbl *)&UFG::TeleportEvent::`vftable;
  this->mSimObjectUID = uidSimObject;
  this->mXFormComponentUID = uidXForm;
  this->mLocalOnly = 0;
  v6 = UFG::qMatrix44::msIdentity.v0.y;
  v7 = UFG::qMatrix44::msIdentity.v0.z;
  v8 = UFG::qMatrix44::msIdentity.v0.w;
  this->m_Xform.v0.x = UFG::qMatrix44::msIdentity.v0.x;
  this->m_Xform.v0.y = v6;
  this->m_Xform.v0.z = v7;
  this->m_Xform.v0.w = v8;
  v9 = UFG::qMatrix44::msIdentity.v1.y;
  v10 = UFG::qMatrix44::msIdentity.v1.z;
  v11 = UFG::qMatrix44::msIdentity.v1.w;
  this->m_Xform.v1.x = UFG::qMatrix44::msIdentity.v1.x;
  this->m_Xform.v1.y = v9;
  this->m_Xform.v1.z = v10;
  this->m_Xform.v1.w = v11;
  v12 = UFG::qMatrix44::msIdentity.v2.y;
  v13 = UFG::qMatrix44::msIdentity.v2.z;
  v14 = UFG::qMatrix44::msIdentity.v2.w;
  this->m_Xform.v2.x = UFG::qMatrix44::msIdentity.v2.x;
  this->m_Xform.v2.y = v12;
  this->m_Xform.v2.z = v13;
  this->m_Xform.v2.w = v14;
  v15 = UFG::qMatrix44::msIdentity.v3.y;
  v16 = UFG::qMatrix44::msIdentity.v3.z;
  v17 = UFG::qMatrix44::msIdentity.v3.w;
  this->m_Xform.v3.x = UFG::qMatrix44::msIdentity.v3.x;
  this->m_Xform.v3.y = v15;
  this->m_Xform.v3.z = v16;
  this->m_Xform.v3.w = v17;
}

// File Line: 62
// RVA: 0x202A60
void __fastcall UFG::TeleportEvent::TeleportEvent(UFG::TeleportEvent *this, UFG::qMatrix44 *worldXform, unsigned int uidSimObject, unsigned int uidXForm, const char *pName, bool localOnly)
{
  unsigned int v6; // er10
  UFG::qNode<UFG::Event,UFG::Event> *v7; // rax
  float v8; // xmm1_4
  float v9; // xmm2_4
  float v10; // xmm3_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  float v13; // xmm3_4
  float v14; // xmm1_4
  float v15; // xmm2_4
  float v16; // xmm3_4
  float v17; // xmm1_4
  float v18; // xmm2_4
  float v19; // xmm3_4

  v6 = UFG::TeleportEvent::EVENT_UID;
  v7 = (UFG::qNode<UFG::Event,UFG::Event> *)&this->mPrev;
  v7->mPrev = v7;
  v7->mNext = v7;
  this->vfptr = (UFG::EventVtbl *)&UFG::Event::`vftable;
  this->m_EventUID = v6;
  this->m_NamePTR = pName;
  this->vfptr = (UFG::EventVtbl *)&UFG::TeleportEvent::`vftable;
  this->mSimObjectUID = uidSimObject;
  this->mXFormComponentUID = uidXForm;
  this->mLocalOnly = localOnly;
  v8 = worldXform->v0.y;
  v9 = worldXform->v0.z;
  v10 = worldXform->v0.w;
  this->m_Xform.v0.x = worldXform->v0.x;
  this->m_Xform.v0.y = v8;
  this->m_Xform.v0.z = v9;
  this->m_Xform.v0.w = v10;
  v11 = worldXform->v1.y;
  v12 = worldXform->v1.z;
  v13 = worldXform->v1.w;
  this->m_Xform.v1.x = worldXform->v1.x;
  this->m_Xform.v1.y = v11;
  this->m_Xform.v1.z = v12;
  this->m_Xform.v1.w = v13;
  v14 = worldXform->v2.y;
  v15 = worldXform->v2.z;
  v16 = worldXform->v2.w;
  this->m_Xform.v2.x = worldXform->v2.x;
  this->m_Xform.v2.y = v14;
  this->m_Xform.v2.z = v15;
  this->m_Xform.v2.w = v16;
  v17 = worldXform->v3.y;
  v18 = worldXform->v3.z;
  v19 = worldXform->v3.w;
  this->m_Xform.v3.x = worldXform->v3.x;
  this->m_Xform.v3.y = v17;
  this->m_Xform.v3.z = v18;
  this->m_Xform.v3.w = v19;
}

// File Line: 69
// RVA: 0x405620
void __fastcall UFG::TeleportEvent::TeleportEvent(UFG::TeleportEvent *this, UFG::qVector3 *position, unsigned int uidSimObject, unsigned int uidXForm, const char *pName, bool localOnly)
{
  unsigned int v6; // er10
  UFG::qNode<UFG::Event,UFG::Event> *v7; // rax

  v6 = UFG::TeleportEvent::EVENT_UID;
  v7 = (UFG::qNode<UFG::Event,UFG::Event> *)&this->mPrev;
  v7->mPrev = v7;
  v7->mNext = v7;
  this->vfptr = (UFG::EventVtbl *)&UFG::Event::`vftable;
  this->m_EventUID = v6;
  this->m_NamePTR = pName;
  this->vfptr = (UFG::EventVtbl *)&UFG::TeleportEvent::`vftable;
  this->mSimObjectUID = uidSimObject;
  this->mXFormComponentUID = uidXForm;
  this->mLocalOnly = localOnly;
  UFG::qTranslationMatrix(&this->m_Xform, position);
}

// File Line: 85
// RVA: 0x1B9DE0
void __fastcall UFG::TeleportEvent::TeleportEvent(UFG::TeleportEvent *this, UFG::qVector3 *origin, UFG::qVector3 *dir, unsigned int uidSimObject, unsigned int uidXForm, const char *pName, UFG::qVector3 *upDir)
{
  unsigned int v7; // er10
  UFG::qNode<UFG::Event,UFG::Event> *v8; // rax
  float v9; // xmm7_4
  __m128 v10; // xmm8
  __m128 v11; // xmm6
  __m128 v12; // xmm2
  float v13; // xmm1_4
  float v14; // xmm6_4
  float v15; // xmm7_4
  float v16; // xmm8_4
  __m128 v17; // xmm5
  __m128 v18; // xmm10
  float v19; // xmm9_4
  __m128 v20; // xmm2
  float v21; // xmm1_4
  float v22; // xmm9_4
  float v23; // xmm10_4
  float v24; // xmm11_4
  float v25; // xmm12_4
  __m128 v26; // xmm2
  float v27; // xmm1_4
  float v28; // xmm11_4
  float v29; // xmm12_4
  float v30; // xmm5_4
  float v31; // xmm7_4
  float v32; // xmm8_4
  __m128 v33; // xmm5
  float v34; // xmm3_4
  float v35; // xmm1_4
  float v36; // xmm2_4

  v7 = UFG::TeleportEvent::EVENT_UID;
  v8 = (UFG::qNode<UFG::Event,UFG::Event> *)&this->mPrev;
  v8->mPrev = v8;
  v8->mNext = v8;
  this->vfptr = (UFG::EventVtbl *)&UFG::Event::`vftable;
  this->m_EventUID = v7;
  this->m_NamePTR = pName;
  this->vfptr = (UFG::EventVtbl *)&UFG::TeleportEvent::`vftable;
  this->mSimObjectUID = uidSimObject;
  this->mXFormComponentUID = uidXForm;
  this->mLocalOnly = 0;
  v9 = dir->y;
  v10 = (__m128)LODWORD(dir->x);
  v11 = (__m128)LODWORD(dir->z);
  v12 = v10;
  v12.m128_f32[0] = (float)((float)(v10.m128_f32[0] * v10.m128_f32[0]) + (float)(v9 * v9))
                  + (float)(v11.m128_f32[0] * v11.m128_f32[0]);
  if ( v12.m128_f32[0] == 0.0 )
    v13 = 0.0;
  else
    v13 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v12));
  v14 = v11.m128_f32[0] * v13;
  v15 = v9 * v13;
  v16 = v10.m128_f32[0] * v13;
  this->m_Xform.v0.x = v16;
  this->m_Xform.v0.y = v15;
  this->m_Xform.v0.z = v14;
  this->m_Xform.v0.w = 0.0;
  v17 = (__m128)LODWORD(upDir->y);
  v18 = (__m128)LODWORD(upDir->x);
  v19 = upDir->z;
  v20 = v18;
  v20.m128_f32[0] = (float)((float)(v18.m128_f32[0] * v18.m128_f32[0]) + (float)(v17.m128_f32[0] * v17.m128_f32[0]))
                  + (float)(v19 * v19);
  if ( v20.m128_f32[0] == 0.0 )
    v21 = 0.0;
  else
    v21 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v20));
  v22 = v19 * v21;
  v17.m128_f32[0] = v17.m128_f32[0] * v21;
  v23 = v18.m128_f32[0] * v21;
  v24 = (float)(v23 * v15) - (float)(v17.m128_f32[0] * v16);
  v25 = (float)(v22 * v16) - (float)(v23 * v14);
  v17.m128_f32[0] = (float)(v17.m128_f32[0] * v14) - (float)(v22 * v15);
  v26 = v17;
  v26.m128_f32[0] = (float)((float)(v17.m128_f32[0] * v17.m128_f32[0]) + (float)(v25 * v25)) + (float)(v24 * v24);
  if ( v26.m128_f32[0] == 0.0 )
    v27 = 0.0;
  else
    v27 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v26));
  v28 = v24 * v27;
  v29 = v25 * v27;
  v30 = v17.m128_f32[0] * v27;
  this->m_Xform.v1.x = v30;
  this->m_Xform.v1.y = v29;
  this->m_Xform.v1.z = v28;
  this->m_Xform.v1.w = 0.0;
  v11.m128_f32[0] = v15;
  v31 = (float)(v16 * v29) - (float)(v15 * v30);
  v32 = (float)(this->m_Xform.v0.z * v30) - (float)(v16 * v28);
  v11.m128_f32[0] = (float)(v11.m128_f32[0] * v28) - (float)(this->m_Xform.v0.z * v29);
  v33 = v11;
  v33.m128_f32[0] = (float)((float)(v11.m128_f32[0] * v11.m128_f32[0]) + (float)(v32 * v32)) + (float)(v31 * v31);
  if ( v33.m128_f32[0] == 0.0 )
    v34 = 0.0;
  else
    v34 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v33));
  this->m_Xform.v2.x = v34 * v11.m128_f32[0];
  this->m_Xform.v2.y = v34 * v32;
  this->m_Xform.v2.z = v34 * v31;
  this->m_Xform.v2.w = 0.0;
  v35 = origin->y;
  v36 = origin->z;
  this->m_Xform.v3.x = origin->x;
  this->m_Xform.v3.y = v35;
  this->m_Xform.v3.z = v36;
  this->m_Xform.v3.w = 1.0;
}

// File Line: 254
// RVA: 0xA3AA20
void __fastcall UFG::UIMouseEvent::UIMouseEvent(UFG::UIMouseEvent *this, const char *name)
{
  UFG::UIMouseEvent *v2; // rbx
  UFG::qNode<UFG::Event,UFG::Event> *v3; // rax

  v2 = this;
  v3 = (UFG::qNode<UFG::Event,UFG::Event> *)&this->mPrev;
  v3->mPrev = v3;
  v3->mNext = v3;
  this->vfptr = (UFG::EventVtbl *)&UFG::Event::`vftable;
  this->m_NamePTR = name;
  this->m_EventUID = UFG::qStringHash32(name, 0xFFFFFFFF);
  v2->vfptr = (UFG::EventVtbl *)&UFG::UIMouseEvent::`vftable;
  *(_QWORD *)&v2->winMsg = 0i64;
  *(_QWORD *)&v2->mouseY = 0i64;
  v2->mouseWheel = 0;
}

