#include <ROOT/RColumnElement.hxx>
#include <benchmark/benchmark.h>
#include <rootbench/RBConfig.h>

static void BM_RNTuple_UnpackingBool(benchmark::State &state)
{
   ROOT::Experimental::Detail::RColumnElement<bool, ROOT::Experimental::EColumnType::kBit> element(nullptr);
   bool *unpacked = new bool[state.range(0)];
   for (int i = 0; i < state.range(0); ++i)
      unpacked[i] = ((i % 2) == 0);
   unsigned char *packed = new unsigned char[(state.range(0) + 7) / 8];

   element.Pack(packed, unpacked, state.range(0));

   for (auto _ : state) {
      element.Unpack(unpacked, packed, state.range(0));
   }

   state.SetItemsProcessed(state.range(0) * state.iterations());
   state.SetBytesProcessed(state.range(0) * state.iterations());

   delete[] packed;
   delete[] unpacked;
}
// Arg is the number of elements of the page
BENCHMARK(BM_RNTuple_UnpackingBool)->Unit(benchmark::kNanosecond)->Repetitions(3)
   ->Arg(100)->Arg(100000);


static void BM_RNTuple_UnpackingFloat(benchmark::State &state)
{
   ROOT::Experimental::Detail::RColumnElement<float, ROOT::Experimental::EColumnType::kReal32> element(nullptr);
   float *unpacked = new float[state.range(0)];
   for (int i = 0; i < state.range(0); ++i)
      unpacked[i] = i;
   float *packed = new float[state.range(0)];

   element.Pack(packed, unpacked, state.range(0));

   for (auto _ : state) {
      element.Unpack(unpacked, packed, state.range(0));
   }

   state.SetItemsProcessed(state.range(0) * state.iterations());
   state.SetBytesProcessed(state.range(0) * state.iterations() * sizeof(float));

   delete[] packed;
   delete[] unpacked;
}
// Arg is the number of elements of the page
BENCHMARK(BM_RNTuple_UnpackingFloat)->Unit(benchmark::kNanosecond)->Repetitions(3)
   ->Arg(100)->Arg(100000);


static void BM_RNTuple_UnpackingDouble(benchmark::State &state)
{
   ROOT::Experimental::Detail::RColumnElement<double, ROOT::Experimental::EColumnType::kReal64> element(nullptr);
   double *unpacked = new double[state.range(0)];
   for (int i = 0; i < state.range(0); ++i)
      unpacked[i] = i;
   double *packed = new double[state.range(0)];

   element.Pack(packed, unpacked, state.range(0));

   for (auto _ : state) {
      element.Unpack(unpacked, packed, state.range(0));
   }

   state.SetItemsProcessed(state.range(0) * state.iterations());
   state.SetBytesProcessed(state.range(0) * state.iterations() * sizeof(double));

   delete[] packed;
   delete[] unpacked;
}
// Arg is the number of elements of the page
BENCHMARK(BM_RNTuple_UnpackingDouble)->Unit(benchmark::kNanosecond)->Repetitions(3)
   ->Arg(100)->Arg(100000);


static void BM_RNTuple_UnpackingInt32(benchmark::State &state)
{
   ROOT::Experimental::Detail::RColumnElement<std::int32_t, ROOT::Experimental::EColumnType::kInt32> element(nullptr);
   std::int32_t *unpacked = new std::int32_t[state.range(0)];
   for (int i = 0; i < state.range(0); ++i)
      unpacked[i] = ((-1) * (i + 1)) * i;
   std::int32_t *packed = new std::int32_t[state.range(0)];

   element.Pack(packed, unpacked, state.range(0));

   for (auto _ : state) {
      element.Unpack(unpacked, packed, state.range(0));
   }

   state.SetItemsProcessed(state.range(0) * state.iterations());
   state.SetBytesProcessed(state.range(0) * state.iterations() * sizeof(std::int32_t));

   delete[] packed;
   delete[] unpacked;
}
// Arg is the number of elements of the page
BENCHMARK(BM_RNTuple_UnpackingInt32)->Unit(benchmark::kNanosecond)->Repetitions(3)
   ->Arg(100)->Arg(100000);


static void BM_RNTuple_UnpackingUInt32(benchmark::State &state)
{
   ROOT::Experimental::Detail::RColumnElement<std::uint32_t, ROOT::Experimental::EColumnType::kInt32> element(nullptr);
   std::uint32_t *unpacked = new std::uint32_t[state.range(0)];
   for (int i = 0; i < state.range(0); ++i)
      unpacked[i] = i;
   std::uint32_t *packed = new std::uint32_t[state.range(0)];

   element.Pack(packed, unpacked, state.range(0));

   for (auto _ : state) {
      element.Unpack(unpacked, packed, state.range(0));
   }

   state.SetItemsProcessed(state.range(0) * state.iterations());
   state.SetBytesProcessed(state.range(0) * state.iterations() * sizeof(std::uint32_t));

   delete[] packed;
   delete[] unpacked;
}
// Arg is the number of elements of the page
BENCHMARK(BM_RNTuple_UnpackingUInt32)->Unit(benchmark::kNanosecond)->Repetitions(3)
   ->Arg(100)->Arg(100000);


static void BM_RNTuple_UnpackingInt64(benchmark::State &state)
{
   ROOT::Experimental::Detail::RColumnElement<std::int64_t, ROOT::Experimental::EColumnType::kInt64> element(nullptr);
   std::int64_t *unpacked = new std::int64_t[state.range(0)];
   for (int i = 0; i < state.range(0); ++i)
      unpacked[i] = ((-1) * (i + 1)) * i;
   std::int64_t *packed = new std::int64_t[state.range(0)];

   element.Pack(packed, unpacked, state.range(0));

   for (auto _ : state) {
      element.Unpack(unpacked, packed, state.range(0));
   }

   state.SetItemsProcessed(state.range(0) * state.iterations());
   state.SetBytesProcessed(state.range(0) * state.iterations() * sizeof(std::int64_t));

   delete[] packed;
   delete[] unpacked;
}
// Arg is the number of elements of the page
BENCHMARK(BM_RNTuple_UnpackingInt64)->Unit(benchmark::kNanosecond)->Repetitions(3)
   ->Arg(100)->Arg(100000);


static void BM_RNTuple_UnpackingUInt64(benchmark::State &state)
{
   ROOT::Experimental::Detail::RColumnElement<std::uint64_t, ROOT::Experimental::EColumnType::kInt64> element(nullptr);
   std::uint64_t *unpacked = new std::uint64_t[state.range(0)];
   for (int i = 0; i < state.range(0); ++i)
      unpacked[i] = i;
   std::uint64_t *packed = new std::uint64_t[state.range(0)];

   element.Pack(packed, unpacked, state.range(0));

   for (auto _ : state) {
      element.Unpack(unpacked, packed, state.range(0));
   }

   state.SetItemsProcessed(state.range(0) * state.iterations());
   state.SetBytesProcessed(state.range(0) * state.iterations() * sizeof(std::uint64_t));

   delete[] packed;
   delete[] unpacked;
}
// Arg is the number of elements of the page
BENCHMARK(BM_RNTuple_UnpackingUInt64)->Unit(benchmark::kNanosecond)->Repetitions(3)
   ->Arg(100)->Arg(100000);


static void BM_RNTuple_UnpackingOffset(benchmark::State &state)
{
   ROOT::Experimental::Detail::RColumnElement<
      ROOT::Experimental::ClusterSize_t, ROOT::Experimental::EColumnType::kIndex> element(nullptr);
   ROOT::Experimental::ClusterSize_t *unpacked = new ROOT::Experimental::ClusterSize_t[state.range(0)];
   for (int i = 0; i < state.range(0); ++i)
      unpacked[i] = i;
   ROOT::Experimental::ClusterSize_t *packed = new ROOT::Experimental::ClusterSize_t[state.range(0)];

   element.Pack(packed, unpacked, state.range(0));

   for (auto _ : state) {
      element.Unpack(unpacked, packed, state.range(0));
   }

   state.SetItemsProcessed(state.range(0) * state.iterations());
   state.SetBytesProcessed(state.range(0) * state.iterations() * sizeof(ROOT::Experimental::ClusterSize_t));

   delete[] packed;
   delete[] unpacked;
}
// Arg is the number of elements of the page
BENCHMARK(BM_RNTuple_UnpackingOffset)->Unit(benchmark::kNanosecond)->Repetitions(3)
   ->Arg(100)->Arg(100000);

BENCHMARK_MAIN();

