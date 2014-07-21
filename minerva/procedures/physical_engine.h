#pragma once
#include "procedures/dag_procedure.h"
#include "op/runner_wrapper.h"
#include "common/common.h"
#include <functional>
#include <string>
#include <vector>
#include <unordered_map>
#include <cstdint>

namespace minerva {

struct NodeState {
  enum State {
    kNoNeed,
    kReady,
    kComplete,
class PhysicalEngine: public PhysicalDagProcedure {
 public:
  // TODO use reference to reduce overhead
  PhysicalEngine();
  ~PhysicalEngine();
  PhysicalEngine& RegisterRunner(std::string, RunnerWrapper::Runner);
  RunnerWrapper::ID GetRunnerID(std::string);
  RunnerWrapper GetRunnerWrapper(RunnerWrapper::ID);
  void Process(PhysicalDag&, std::vector<uint64_t>&);

 private:
  DISALLOW_COPY_AND_ASSIGN(PhysicalEngine);
  void Init();
  void LoadBuiltinRunners();
  std::unordered_map<RunnerWrapper::ID, RunnerWrapper> runners_;
  std::unordered_map<std::string, RunnerWrapper::ID> reverse_lookup_;
  RunnerWrapper::ID index_ = 0;
};

}

