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
  float mTotalFrames; // xmm1_4
  signed __int64 mTotalTime; // rax
  float v3; // xmm0_4
  float v4; // xmm0_4

  if ( this->mTiming )
  {
    if ( !this->mLastFramePaused )
    {
      this->mTotalTime += UFG::Metrics::msRealTimeMSec - this->mStartTime;
      this->mTotalFrames += UFG::Metrics::msFrameCount - this->mStartFrame;
    }
    mTotalFrames = (float)(int)this->mTotalFrames;
    mTotalTime = this->mTotalTime;
    v3 = (float)(int)mTotalTime;
    if ( mTotalTime < 0 )
      v3 = v3 + 1.8446744e19;
    this->mTiming = 0;
    this->mLastResult.averageFPS = mTotalFrames / (float)(v3 * 0.001);
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
  bool v2; // di
  bool v3; // cl
  float v4; // xmm0_4
  float v5; // xmm2_4
  float v6; // xmm1_4
  float v7; // xmm2_4
  float v8; // xmm0_4
  float v9; // xmm2_4
  float v10; // xmm2_4
  float mMaxDeltaMS; // xmm0_4
  float mMinDeltaMS; // xmm0_4
  unsigned int v13; // eax
  unsigned int v14; // eax

  if ( this->mTiming )
  {
    v2 = !UFG::LoadingLogic::IsLoadingScreenUp(&UFG::gLoadingLogic)
      && (unsigned int)UFG::FlowController::GetCurrentState(&UFG::gFlowController) != uidGameStateFE_2
      && !Render::IsLoadScreenRendering();
    v3 = this->mBenchmarkPaused
      || (unsigned __int8)UFG::UI::IsGamePaused()
      || !UFG::UIHK_NISOverlay::IsCurtainHidden()
      || !v2;
    --this->mStartDelayCounter;
    v4 = this->mTimeElapsedArray[2];
    v5 = this->mTimeElapsedArray[3];
    v6 = this->mTimeElapsedArray[1];
    this->mTimeElapsedArray[4] = v5;
    v7 = v5 + v4;
    this->mTimeElapsedArray[3] = v4;
    v8 = this->mTimeElapsedArray[0];
    this->mTimeElapsedArray[2] = v6;
    this->mTimeElapsedArray[1] = v8;
    this->mTimeElapsedArray[0] = UFG::Metrics::msRealTimeDelta_Accurate;
    v9 = (float)((float)(v7 + v6) + v8) + UFG::Metrics::msRealTimeDelta_Accurate;
    if ( !v3 && this->mStartDelayCounter <= 0 )
    {
      v10 = v9 * 0.2;
      mMaxDeltaMS = this->mMaxDeltaMS;
      if ( mMaxDeltaMS <= v10 )
        mMaxDeltaMS = v10;
      this->mMaxDeltaMS = mMaxDeltaMS;
      mMinDeltaMS = this->mMinDeltaMS;
      if ( mMinDeltaMS >= v10 )
        mMinDeltaMS = v10;
      this->mMinDeltaMS = mMinDeltaMS;
    }
    if ( this->mLastFramePaused != v3 )
    {
      if ( v3 )
      {
        this->mTotalTime += UFG::Metrics::msRealTimeMSec - this->mStartTime;
        v13 = UFG::Metrics::msFrameCount;
        this->mLastFramePaused = v3;
        this->mTotalFrames += v13 - this->mStartFrame;
      }
      else
      {
        this->mStartTime = UFG::Metrics::msRealTimeMSec;
        v14 = UFG::Metrics::msFrameCount;
        this->mLastFramePaused = 0;
        this->mStartFrame = v14;
      }
    }
  }
}

// File Line: 126
// RVA: 0x3FC810
UFG::BenchmarkHelper::BenchmarkResult *__fastcall UFG::BenchmarkHelper::GetLastResults(
        UFG::BenchmarkHelper *this,
        UFG::BenchmarkHelper::BenchmarkResult *result)
{
  *result = this->mLastResult;
  return result;
}

// File Line: 131
// RVA: 0x3FD650
void __fastcall UFG::BenchmarkHelper::WriteLastResults(UFG::BenchmarkHelper *this)
{
  UFG::qFile *v2; // rbx
  UFG::qDateTime date_time; // [rsp+28h] [rbp-70h] BYREF
  UFG::qString v4; // [rsp+38h] [rbp-60h] BYREF
  UFG::qString result; // [rsp+60h] [rbp-38h] BYREF

  UFG::qGetDateTime(&date_time);
  UFG::qToString(&result, &date_time, DATETIME_SORTABLE_EXCLUDE_MS, DATETIME_FILENAME_SAFE);
  UFG::qString::qString(&v4);
  UFG::qString::Format(&v4, "BenchmarkResult-%s.xml", result.mData);
  v2 = SimpleXML::XMLWriter::Create(v4.mData, 1, 0x8000u);
  SimpleXML::XMLWriter::AddComment((SimpleXML::XMLWriter *)v2, result.mData);
  SimpleXML::XMLWriter::BeginNode((SimpleXML::XMLWriter *)v2, "Benchmark");
  SimpleXML::XMLWriter::BeginNode((SimpleXML::XMLWriter *)v2, "FPS");
  SimpleXML::XMLWriter::BeginNode((SimpleXML::XMLWriter *)v2, "Average");
  SimpleXML::XMLWriter::AddAttribute((SimpleXML::XMLWriter *)v2, "value", this->mLastResult.averageFPS);
  SimpleXML::XMLWriter::EndNode((SimpleXML::XMLWriter *)v2, "Average");
  SimpleXML::XMLWriter::BeginNode((SimpleXML::XMLWriter *)v2, "Max");
  SimpleXML::XMLWriter::AddAttribute((SimpleXML::XMLWriter *)v2, "value", this->mLastResult.maxFPS);
  SimpleXML::XMLWriter::EndNode((SimpleXML::XMLWriter *)v2, "Max");
  SimpleXML::XMLWriter::BeginNode((SimpleXML::XMLWriter *)v2, "Min");
  SimpleXML::XMLWriter::AddAttribute((SimpleXML::XMLWriter *)v2, "value", this->mLastResult.minFPS);
  SimpleXML::XMLWriter::EndNode((SimpleXML::XMLWriter *)v2, "Min");
  SimpleXML::XMLWriter::EndNode((SimpleXML::XMLWriter *)v2, "FPS");
  SimpleXML::XMLWriter::EndNode((SimpleXML::XMLWriter *)v2, "Benchmark");
  SimpleXML::XMLWriter::Close((SimpleXML::XMLWriter *)v2);
  UFG::qString::~qString(&v4);
  UFG::qString::~qString(&result);
}

