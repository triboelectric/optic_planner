#ifndef PLANSYS2_OPTIC_PLAN_SOLVER__OPTIC_PLAN_SOLVER_HPP_
#define PLANSYS2_OPTIC_PLAN_SOLVER__OPTIC_PLAN_SOLVER_HPP_

#include <filesystem>
#include <optional>
#include <memory>
#include <string>

#include "plansys2_core/PlanSolverBase.hpp"

namespace plansys2
{

class OPTICPlanSolver : public PlanSolverBase
{
private:
  std::string arguments_parameter_name_;
  std::string output_dir_parameter_name_;
  bool cancel_requested_;

public:
  OPTICPlanSolver();

  std::optional<std::filesystem::path> create_folders(const std::string & node_namespace);

  void configure(rclcpp_lifecycle::LifecycleNode::SharedPtr, const std::string &) override;

  std::optional<plansys2_msgs::msg::Plan> getPlan(
    const std::string & domain, const std::string & problem,
    const std::string & node_namespace = "",
    const rclcpp::Duration solver_timeout = 15s);

  bool isDomainValid(
    const std::string & domain,
    const std::string & node_namespace = "");

protected:
  std::optional<plansys2_msgs::msg::Plan> parse_plan_result(const std::string & plan_path);
};

}  // namespace plansys2

#endif  // PLANSYS2_OPTIC_PLAN_SOLVER__OPTIC_PLAN_SOLVER_HPP_
