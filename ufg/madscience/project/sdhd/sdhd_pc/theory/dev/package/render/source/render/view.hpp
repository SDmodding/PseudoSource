// File Line: 151
// RVA: 0xCE70
void __fastcall Render::ViewSettings::ViewSettings(Render::ViewSettings *this, UFG::qMatrix44 *world_view, UFG::qMatrix44 *projection, int cull_index, float cull_pixel_density_threshold, float cull_pixel_distance_bias)
{
  float v6; // eax
  float v7; // xmm1_4
  float v8; // xmm2_4
  float v9; // xmm1_4
  float v10; // eax
  float v11; // xmm2_4
  float v12; // xmm1_4
  float v13; // eax
  float v14; // xmm2_4
  float v15; // xmm1_4
  float v16; // eax
  float v17; // xmm2_4
  float v18; // xmm1_4
  float v19; // eax
  float v20; // xmm2_4
  float v21; // xmm1_4
  float v22; // eax
  float v23; // xmm2_4
  float v24; // xmm1_4
  float v25; // eax
  float v26; // xmm2_4
  float v27; // xmm1_4
  float v28; // eax
  float v29; // xmm2_4

  v6 = world_view->v0.x;
  v7 = world_view->v0.z;
  v8 = world_view->v0.w;
  this->mWorldView.v0.y = world_view->v0.y;
  this->mWorldView.v0.z = v7;
  this->mWorldView.v0.x = v6;
  this->mWorldView.v0.w = v8;
  v9 = world_view->v1.z;
  v10 = world_view->v1.x;
  v11 = world_view->v1.w;
  this->mWorldView.v1.y = world_view->v1.y;
  this->mWorldView.v1.z = v9;
  this->mWorldView.v1.x = v10;
  this->mWorldView.v1.w = v11;
  v12 = world_view->v2.z;
  v13 = world_view->v2.x;
  v14 = world_view->v2.w;
  this->mWorldView.v2.y = world_view->v2.y;
  this->mWorldView.v2.z = v12;
  this->mWorldView.v2.x = v13;
  this->mWorldView.v2.w = v14;
  v15 = world_view->v3.z;
  v16 = world_view->v3.x;
  v17 = world_view->v3.w;
  this->mWorldView.v3.y = world_view->v3.y;
  this->mWorldView.v3.z = v15;
  this->mWorldView.v3.x = v16;
  this->mWorldView.v3.w = v17;
  v18 = projection->v0.z;
  v19 = projection->v0.x;
  v20 = projection->v0.w;
  this->mProjection.v0.y = projection->v0.y;
  this->mProjection.v0.z = v18;
  this->mProjection.v0.x = v19;
  this->mProjection.v0.w = v20;
  v21 = projection->v1.z;
  v22 = projection->v1.x;
  v23 = projection->v1.w;
  this->mProjection.v1.y = projection->v1.y;
  this->mProjection.v1.z = v21;
  this->mProjection.v1.x = v22;
  this->mProjection.v1.w = v23;
  v24 = projection->v2.z;
  v25 = projection->v2.x;
  v26 = projection->v2.w;
  this->mProjection.v2.y = projection->v2.y;
  this->mProjection.v2.z = v24;
  this->mProjection.v2.x = v25;
  this->mProjection.v2.w = v26;
  v27 = projection->v3.z;
  v28 = projection->v3.x;
  v29 = projection->v3.w;
  this->mProjection.v3.y = projection->v3.y;
  this->mProjection.v3.x = v28;
  this->mProjection.v3.z = v27;
  this->mProjection.v3.w = v29;
  this->mCullIndex = cull_index;
  this->mCullPixelDensityThreshold = cull_pixel_density_threshold;
  this->mCullPixelDistanceBias = cull_pixel_distance_bias;
}

