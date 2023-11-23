// File Line: 25
// RVA: 0x3BCD40
void __fastcall UFG::PhotoTarget::PhotoTarget(
        UFG::PhotoTarget *this,
        UFG::qVector3 *position,
        bool upload,
        float delay)
{
  float y; // xmm1_4
  float z; // xmm2_4
  float v9; // xmm1_4
  float v10; // xmm2_4

  UFG::RebindingComponentHandle<UFG::CameraSubject,0>::RebindingComponentHandle<UFG::CameraSubject,0>(&this->mTargetSubject);
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0>::RebindingComponentHandle<UFG::TransformNodeComponent,0>(&this->mTargetTransform);
  this->vMin.x = -0.60000002;
  this->vMin.y = -0.60000002;
  this->vMin.z = 0.1;
  this->vMin.w = -3.1415927;
  this->vMax.x = 0.60000002;
  this->vMax.y = 0.60000002;
  this->vMax.z = 0.80000001;
  this->vMax.w = 3.1415927;
  y = position->y;
  z = position->z;
  this->vPosition.x = position->x;
  this->vPosition.y = y;
  this->vPosition.z = z;
  v9 = UFG::qVector3::msAxisX.y;
  v10 = UFG::qVector3::msAxisX.z;
  this->vForward.x = UFG::qVector3::msAxisX.x;
  this->vForward.y = v9;
  this->vForward.z = v10;
  this->bFrontOnly = 0;
  this->bUpload = upload;
  this->nUID = 0;
  this->fDelay = delay;
  *(_WORD *)&this->bValid = 0;
  this->bClearLOS = 0;
  *(_QWORD *)&this->fTimer = 0i64;
}

// File Line: 26
// RVA: 0x3BCE40
void __fastcall UFG::PhotoTarget::PhotoTarget(
        UFG::PhotoTarget *this,
        UFG::SimObject *object,
        bool frontOnly,
        bool upload,
        float delay)
{
  UFG::RebindingComponentHandle<UFG::CameraSubject,0>::RebindingComponentHandle<UFG::CameraSubject,0>(&this->mTargetSubject);
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0>::RebindingComponentHandle<UFG::TransformNodeComponent,0>(&this->mTargetTransform);
  UFG::PhotoTarget::Init(this, object, &UFG::qVector3::msZero, frontOnly, upload, delay);
}

// File Line: 27
// RVA: 0x3BCED0
void __fastcall UFG::PhotoTarget::PhotoTarget(
        UFG::PhotoTarget *this,
        UFG::TransformNodeComponent *node,
        bool frontOnly,
        bool upload,
        float delay)
{
  UFG::SimObject *m_pSimObject; // rdx

  UFG::RebindingComponentHandle<UFG::CameraSubject,0>::RebindingComponentHandle<UFG::CameraSubject,0>(&this->mTargetSubject);
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0>::RebindingComponentHandle<UFG::TransformNodeComponent,0>(&this->mTargetTransform);
  do
  {
    m_pSimObject = node->m_pSimObject;
    node = node->mParent;
  }
  while ( !m_pSimObject && node );
  UFG::PhotoTarget::Init(this, m_pSimObject, &UFG::qVector3::msZero, frontOnly, upload, delay);
}

