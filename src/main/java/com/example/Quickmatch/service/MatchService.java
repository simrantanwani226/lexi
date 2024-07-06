package com.example.Quickmatch.service;

import org.springframework.stereotype.Service;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

@Service
public class MatchService {
    public double calculateMatch(String resumeContent, String jobDescriptionContent) {
        Set<String> resumeWords = getWords(resumeContent);
        Set<String> jobDescriptionWords = getWords(jobDescriptionContent);
        
        Set<String> intersection = new HashSet<>(resumeWords);
        intersection.retainAll(jobDescriptionWords); // Get common words
        
        double resumeSize = resumeWords.size();
        double jobDescriptionSize = jobDescriptionWords.size();
        double intersectionSize = intersection.size();

        if (jobDescriptionSize == 0) {
            return 0; // Handle division by zero
        }

        double matchPercentage = (intersectionSize / jobDescriptionSize) * 100;

        // Cap the match percentage at 100%
        return Math.min(matchPercentage, 100);
    }
    
    private Set<String> getWords(String content) {
        String[] wordsArray = content.toLowerCase().replaceAll("[^a-zA-Z0-9\\s]", "").split("\\s+");
        return new HashSet<>(Arrays.asList(wordsArray));
    }
}
