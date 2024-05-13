package main

import (
  "fmt"
  "slices"
)

func twoSum(nums []int, target int) []int {
  length := len(nums)
  orig_nums := make([]int, length)
  for i:=0;i<length; i++ {
    orig_nums[i] = nums[i] 
  }
  slices.Sort(nums)
  var p1, p2, m, n = 0,0,0,length-1
  for i:=0; i<length; i++ {
    p1 = nums[m]
    p2 = nums[n]
    if p1+p2 == target{
      fmt.Println(p1, "+", p2, "=", target)
      ind1 := slices.Index(orig_nums, p1)
      ind2 := slices.Index(orig_nums, p2)
      fmt.Println(ind1, ind2)
    }
    if p1+p2 < target{
      m++ 
    } else{
      n--
    }
  }
  return nil
}

func main(){
  nums := []int{2,1,3,4}
  retarr := twoSum(nums, 4)
  fmt.Println(retarr)
}
