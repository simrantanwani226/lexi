package com.example.Quickmatch.controller;

import com.example.Quickmatch.repository.ResumeRepository;
import com.example.Quickmatch.repository.JobDescriptionRepository;
import com.example.Quickmatch.service.MatchService;
import com.example.Quickmatch.model.Resume;
import com.example.Quickmatch.model.JobDescription;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

@RestController
@RequestMapping("/resumes")
public class ResumeController {
    @Autowired
    private ResumeRepository resumeRepository;

    @Autowired
    private MatchService matchService;

    @Autowired
    private JobDescriptionRepository jobDescriptionRepository;

    @PostMapping
    public Resume createResume(@RequestBody Resume resume) {
        return resumeRepository.save(resume);
    }

    @GetMapping("/{id}/match/{jobId}")
    public double matchResume(@PathVariable Long id, @PathVariable Long jobId) {
        Resume resume = resumeRepository.findById(id).orElseThrow();
        JobDescription jobDescription = jobDescriptionRepository.findById(jobId).orElseThrow();
        return matchService.calculateMatch(resume.getContent(), jobDescription.getContent());
    }
}
