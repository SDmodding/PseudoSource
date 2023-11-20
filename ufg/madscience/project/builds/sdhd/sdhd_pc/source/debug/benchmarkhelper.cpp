// File Line: 37
// RVA: 0x3FD4D0
void __fastcall UFG::BenchmarkHelper::StartTiming(UFG::BenchmarkHelper *this)
{
  this->mMaxDeltaMS = -3.4028235e38;
  this->mMinDeltaMS = 3.4028235e38;
  *(_WORD *)&this->mTiming = 257;
  *(_QWORD *)&this->mStartDelayCounter = 15i64;
  this->mTotalTime = 0i64;
  this->mTotalFrames = 0;
  this->mBenchmarkPaused = 0;
  *(_QWORD *)&this->mTimeElapsedArray[1] = 0i64;
  *(_QWORD *)&this->mTimeElapsedArray[3] = 0i64;
}

// File Line: 55
// RVA: 0x3FC790
void __fastcall UFG::BenchmarkHelper::EndTiming(UFG::BenchmarkHelper *this)
{
  float v1; // xmm1_4
  signed __int64 v2; // rax
  float v3; // xmm0_4
  float v4; // xmm0_4

  if ( this->mTiming )
  {
    if ( !this->mLastFramePaused )
    {
      this->mTotalTime += UFG::Metrics::msRealTimeMSec - this->mStartTime;
      this->mTotalFrames += UFG::Metrics::msFrameCount - this->mStartFrame;
    }
    v1 = (float)(signed int)this->mTotalFrames;
    v2 = this->mTotalTime;
    v3 = (float)(signed int)v2;
    if ( v2 < 0 )
      v3 = v3 + 1.8446744e19;
    this->mTiming = 0;
    this->mLastResult.averageFPS = v1 / (float)(v3 * 0.001);
    v4 = 1.0 / this->mMinDeltaMS;
    this->mLastResult.minFPS = 1.0 / this->mMaxDeltaMS;
    this->mLastResult.maxFPS = v4;
  }
}

// File Line: 72
// RVA: 0x3FD3D0
void __fastcall UFG::BenchmarkHelper::PauseTiming(UFG::BenchmarkHelper *this)
{
  this->mBenchmarkPaused = 1;
}

// File Line: 77
// RVA: 0x3FD460
void __fastcall UFG::BenchmarkHelper::ResumeTiming(UFG::BenchmarkHelper *this)
{
  this->mBenchmarkPaused = 0;
  this->mStartDelayCounter = 15;
}

// File Line: 83
// RVA: 0x3FD510
void __fastcall UFG::BenchmarkHelper::Update(UFG::BenchmarkHelper *this)
{
  UFG::BenchmarkHelper *v1; // rbx
  bool v2; // di
  bool v3; // cl
  float v4; // xmm0_4
  float v5; // xmm2_4
  float v6; // xmm1_4
  float v7; // xmm2_4
  float v8; // xmm0_4
  float v9; // xmm2_4
  float v10; // xmm2_4
  float v11; // xmm0_4
  float v12; // xmm0_4
  unsigned int v13; // eax
  unsigned int v14; // eax

  v1 = this;
  if ( this->mTiming )
  {
    v2 = !(unsigned __int8)UFG::LoadingLogic::IsLoadingScreenUp(&UFG::gLoadingLogic)
      && (unsigned int)UFG::FlowController::GetCurrentState(&UFG::gFlowController) != uidGameStateFE_2
      && !(unsigned int)Render::IsLoadScreenRendering();
    v3 = v1->mBenchmarkPaused
      || (unsigned __int8)UFG::UI::IsGamePaused()
      || !UFG::UIHK_NISOverlay::IsCurtainHidden()
      || !v2;
    --v1->mStartDelayCounter;
    v4 = v1->mTimeElapsedArray[2];
    v5 = v1->mTimeElapsedArray[3];
    v6 = v1->mTimeElapsedArray[1];
    v1->mTimeElapsedArray[4] = v5;
    v7 = v5 + v4;
    v1->mTimeElapsedArray[3] = v4;
    v8 = v1->mTimeElapsedArray[0];
    v1->mTimeElapsedArray[2] = v6;
    v1->mTimeElapsedArray[1] = v8;
    v1->mTimeElapsedArray[0] = UFG::Metrics::msRealTimeDelta_Accurate;
    v9 = (float)((float)(v7 + v6) + v8) + UFG::Metrics::msRealTimeDelta_Accurate;
    if ( !v3 && v1->mStartDelayCounter <= 0 )
    {
      v10 = v9 * 0.2;
      v11 = v1->mMaxDeltaMS;
      if ( v11 <= v10 )
        v11 = v10;
      v1->mMaxDeltaMS = v11;
      v12 = v1->mMinDeltaMS;
      if ( v12 >= v10 )
        v12 = v10;
      v1->mMinDeltaMS = v12;
    }
    if ( v1->mLastFramePaused != v3 )
    {
      if ( v3 )
      {
        v1->mTotalTime += UFG::Metrics::msRealTimeMSec - v1->mStartTime;
        v13 = UFG::Metrics::msFrameCount;
        v1->mLastFramePaused = v3;
        v1->mTotalFrames += v13 - v1->mStartFrame;
      }
      else
      {
        v1->mStartTime = UFG::Metrics::msRealTimeMSec;
        v14 = UFG::Metrics::msFrameCount;
        v1->mLastFramePaused = 0;
        v1->mStartFrame = v14;
      }
    }
  }
}

// File Line: 126
// RVA: 0x3FC810
UFG::BenchmarkHelper::BenchmarkResult *__fastcall UFG::BenchmarkHelper::GetLastResults(UFG::BenchmarkHelper *this, UFG::BenchmarkHelper::BenchmarkResult *result)
{
  result->averageFPS = this->mLastResult.averageFPS;
  result->maxFPS = this->mLastResult.maxFPS;
  result->minFPS = this->mLastResult.minFPS;
  return result;
}

// File Line: 131
// RVA: 0x3FD650
void __fastcall UFG::BenchmarkHelper::WriteLastResults(UFG::BenchmarkHelper *this)
{
  UFG::BenchmarkHelper *v1; // rdi
  UFG::qFile *v2; // rbx
  UFG::qDateTime date_time; // [rsp+28h] [rbp-70h]
  UFG::qString v4; // [rsp+38h] [rbp-60h]
  UFG::qString result; // [rsp+60h] [rbp-38h]

  v1 = this;
  UFG::qGetDateTime(&date_time);
  UFG::qToString(&result, &date_time, DATETIME_SORTABLE_EXCLUDE_MS, DATETIME_FILENAME_SAFE);
  UFG::qString::qString(&v4);
  UFG::qString::Format(&v4, "BenchmarkResult-%s.xml", result.mData);
  v2 = SimpleXML::XMLWriter::Create(v4.mData, 1, 0x8000u);
  SimpleXML::XMLWriter::AddComment((SimpleXML::XMLWriter *)v2, result.mData);
  SimpleXML::XMLWriter::BeginNode((SimpleXML::XMLWriter *)v2, "Benchmark");
  SimpleXML::XMLWriter::BeginNode((SimpleXML::XMLWriter *)v2, "FPS");
  SimpleXML::XMLWriter::BeginNode((SimpleXML::XMLWriter *)v2, "Average");
  SimpleXML::XMLWriter::AddAttribute((SimpleXML::XMLWriter *)v2, "value", v1->mLastResult.averageFPS);
  SimpleXML::XMLWriter::EndNode((SimpleXML::XMLWriter *)v2, "Average");
  SimpleXML::XMLWriter::BeginNode((SimpleXML::XMLWriter *)v2, "Max");
  SimpleXML::XMLWriter::AddAttribute((SimpleXML::XMLWriter *)v2, "value", v1->mLastResult.maxFPS);
  SimpleXML::XMLWriter::EndNode((SimpleXML::XMLWriter *)v2, "Max");
  SimpleXML::XMLWriter::BeginNode((SimpleXML::XMLWriter *)v2, "Min");
  SimpleXML::XMLWriter::AddAttribute((SimpleXML::XMLWriter *)v2, "value", v1->mLastResult.minFPS);
  SimpleXML::XMLWriter::EndNode((SimpleXML::XMLWriter *)v2, "Min");
  SimpleXML::XMLWriter::EndNode((SimpleXML::XMLWriter *)v2, "FPS");
  SimpleXML::XMLWriter::EndNode((SimpleXML::XMLWriter *)v2, "Benchmark");
  SimpleXML::XMLWriter::Close((SimpleXML::XMLWriter *)v2);
  UFG::qString::~qString(&v4);
  UFG::qString::~qString(&result);
}

