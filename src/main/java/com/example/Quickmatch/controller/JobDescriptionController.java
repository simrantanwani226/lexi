package com.example.Quickmatch.controller;

import com.example.Quickmatch.model.JobDescription;
import com.example.Quickmatch.repository.JobDescriptionRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

@RestController
@RequestMapping("/jobs")
public class JobDescriptionController {
    @Autowired
    private JobDescriptionRepository jobDescriptionRepository;

    @PostMapping
    public JobDescription createJobDescription(@RequestBody JobDescription jobDescription) {
        return jobDescriptionRepository.save(jobDescription);
    }
}
