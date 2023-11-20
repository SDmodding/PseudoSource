// File Line: 25
// RVA: 0x3BCD40
void __fastcall UFG::PhotoTarget::PhotoTarget(UFG::PhotoTarget *this, UFG::qVector3 *position, bool upload, float delay)
{
  bool v4; // di
  UFG::qVector3 *v5; // rbx
  UFG::PhotoTarget *v6; // rsi
  float v7; // xmm1_4
  float v8; // xmm2_4
  float v9; // xmm1_4
  float v10; // xmm2_4

  v4 = upload;
  v5 = position;
  v6 = this;
  UFG::RebindingComponentHandle<UFG::CameraSubject,0>::RebindingComponentHandle<UFG::CameraSubject,0>(&this->mTargetSubject);
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0>::RebindingComponentHandle<UFG::TransformNodeComponent,0>(&v6->mTargetTransform);
  v6->vMin.x = -0.60000002;
  v6->vMin.y = -0.60000002;
  v6->vMin.z = 0.1;
  v6->vMin.w = -3.1415927;
  v6->vMax.x = 0.60000002;
  v6->vMax.y = 0.60000002;
  v6->vMax.z = 0.80000001;
  v6->vMax.w = 3.1415927;
  v7 = v5->y;
  v8 = v5->z;
  v6->vPosition.x = v5->x;
  v6->vPosition.y = v7;
  v6->vPosition.z = v8;
  v9 = UFG::qVector3::msAxisX.y;
  v10 = UFG::qVector3::msAxisX.z;
  v6->vForward.x = UFG::qVector3::msAxisX.x;
  v6->vForward.y = v9;
  v6->vForward.z = v10;
  v6->bFrontOnly = 0;
  v6->bUpload = v4;
  v6->nUID = 0;
  v6->fDelay = delay;
  *(_WORD *)&v6->bValid = 0;
  v6->bClearLOS = 0;
  *(_QWORD *)&v6->fTimer = 0i64;
}

// File Line: 26
// RVA: 0x3BCE40
void __fastcall UFG::PhotoTarget::PhotoTarget(UFG::PhotoTarget *this, UFG::SimObject *object, bool frontOnly, bool upload, float delay)
{
  bool v5; // bl
  bool v6; // di
  UFG::SimObject *v7; // rsi
  UFG::PhotoTarget *v8; // rbp

  v5 = upload;
  v6 = frontOnly;
  v7 = object;
  v8 = this;
  UFG::RebindingComponentHandle<UFG::CameraSubject,0>::RebindingComponentHandle<UFG::CameraSubject,0>(&this->mTargetSubject);
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0>::RebindingComponentHandle<UFG::TransformNodeComponent,0>(&v8->mTargetTransform);
  UFG::PhotoTarget::Init(v8, v7, &UFG::qVector3::msZero, v6, v5, delay);
}

// File Line: 27
// RVA: 0x3BCED0
void __fastcall UFG::PhotoTarget::PhotoTarget(UFG::PhotoTarget *this, UFG::TransformNodeComponent *node, bool frontOnly, bool upload, float delay)
{
  bool v5; // si
  bool v6; // bp
  UFG::TransformNodeComponent *v7; // rbx
  UFG::PhotoTarget *v8; // rdi
  UFG::SimObject *v9; // rdx

  v5 = upload;
  v6 = frontOnly;
  v7 = node;
  v8 = this;
  UFG::RebindingComponentHandle<UFG::CameraSubject,0>::RebindingComponentHandle<UFG::CameraSubject,0>(&this->mTargetSubject);
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0>::RebindingComponentHandle<UFG::TransformNodeComponent,0>(&v8->mTargetTransform);
  do
  {
    v9 = v7->m_pSimObject;
    v7 = v7->mParent;
  }
  while ( !v9 && v7 );
  UFG::PhotoTarget::Init(v8, v9, &UFG::qVector3::msZero, v6, v5, delay);
}

